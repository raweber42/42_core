/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:00:38 by raweber           #+#    #+#             */
/*   Updated: 2022/06/23 16:56:41 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// allocates a new list element and sets all the values accordingly
t_pipex_list	*pipex_lstnew(char **argv, int argc, char **envp, int cur_argc)
{
	t_pipex_list	*new_node;

	new_node = malloc(sizeof(t_pipex_list));
	if (!new_node)
		pipex_error("Error: Could not allocate node", NULL);
	if (cur_argc < argc - 1)
	{
		new_node->command_splitted = ft_split(argv[cur_argc], 32);
		new_node->list_start = &new_node;
		new_node->here_doc = 0;
		set_command_path(envp, new_node);
		new_node->filename = ft_strdup(argv[argc - 1]);
		new_node->next = NULL;
		if (cur_argc == 2)
			new_node->fd_infile = get_fd_infile(argv[1], new_node);
	}
	new_node->next = NULL;
	return (new_node);
}

// initializes linked list starting from the second
// up to the second last command line argument
void	init_linked_list(t_pipex_list **head, int argc, char **argv, char **env)
{
	int				i;
	t_pipex_list	*new_node;
	int				here_doc;

	i = 2;
	here_doc = 0;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		i = 3;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		here_doc = 1;
	new_node = pipex_lstnew(argv, argc, env, i);
	new_node->list_start = head;
	if (here_doc)
		new_node->here_doc = 1;
	*head = new_node;
	i++;
	while (i < argc - 1)
	{
		new_node = pipex_lstnew(argv, argc, env, i);
		new_node->list_start = head;
		if (here_doc)
			new_node->here_doc = 1;
		pipex_lstadd_back(head, new_node);
		i++;
	}
}

// helper function to add another node to the end of linked list
void	pipex_lstadd_back(t_pipex_list **lst, t_pipex_list *new_node)
{	
	t_pipex_list	*temp;

	temp = *lst;
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
}
