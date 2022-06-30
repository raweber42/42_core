/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:32:27 by raweber           #+#    #+#             */
/*   Updated: 2022/06/23 16:45:34 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// Displays an error and exits the program
int	pipex_error(char *err_msg, t_pipex_list *argument_ll)
{
	ft_putendl_fd(err_msg, 2);
	if (argument_ll)
		destroy_linked_list(argument_ll->list_start);
	exit(1);
}

void	destroy_linked_list(t_pipex_list **list_start)
{
	int				i;
	t_pipex_list	*temp1;

	temp1 = *list_start;
	while (*list_start != NULL)
	{	
		i = 0;
		while (temp1->command_splitted[i])
			free(temp1->command_splitted[i++]);
		if (temp1->command_splitted)
			free(temp1->command_splitted);
		if (temp1->command_path)
			free(temp1->command_path);
		if (temp1->filename)
			free(temp1->filename);
		if (temp1->here_doc)
			unlink(".heredoc");
		temp1 = temp1->next;
		free(*list_start);
		*list_start = temp1;
	}
}
