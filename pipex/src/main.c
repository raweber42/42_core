/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:23:49 by raweber           #+#    #+#             */
/*   Updated: 2022/06/23 15:32:05 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// initializes, pipes and destroys the linked list
int	main(int argc, char **argv, char **envp)
{
	t_pipex_list	*argument_ll;
	int				previous_exists;

	if (argc < 5)
		pipex_error("Error: Use './pipex infile <cmd1> <cmd2> outfile'", NULL);
	argument_ll = NULL;
	init_linked_list(&argument_ll, argc, argv, envp);
	if (argument_ll->here_doc)
		run_here_doc(&argument_ll, argv);
	previous_exists = 0;
	pipe_loop(argument_ll, envp, previous_exists);
	destroy_linked_list(argument_ll->list_start);
}

// loops over every command, runs new child processes and opens new pipes 
// which execute and transmit the commands, respectively
void	pipe_loop(t_pipex_list *argument_ll, char **envp, int previous_exists)
{
	int		pid;
	int		new_fds[2];
	int		old_fds[2];

	while (argument_ll)
	{
		if (argument_ll->next)
		{
			if (pipe(new_fds))
				pipex_error("Error: Could not create pipe", argument_ll);
		}
		pid = fork();
		if (pid == -1)
			pipex_error("Error: Could not fork the process", argument_ll);
		if (pid == 0)
		{
			redirect_child(old_fds, new_fds, argument_ll, previous_exists);
			run_execve(argument_ll, envp);
		}
		redirect_parent(old_fds, new_fds, argument_ll, previous_exists);
		previous_exists = 1;
		argument_ll = argument_ll->next;
	}
}
