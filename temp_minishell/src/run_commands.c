/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:00:44 by raweber           #+#    #+#             */
/*   Updated: 2022/07/06 12:20:14 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// runs command, prints error, if not executed
void	run_execve(t_cmd_struct *cmd_struct, char **envp)
{
	execve(cmd_struct->command_path, cmd_struct->command_splitted, envp);
	ms_error("Error: One of the commands is invalid", cmd_struct);
}

// creates childs, runs commands in them and redirects
// input and output for parent and children
void	run_commands(t_cmd_struct *cmd_struct)
{
	int		pid;
	int		new_fds[2];
	int		old_fds[2];

	while (cmd_struct)
	{
		if (cmd_struct->next)
		{
			if (pipe(new_fds))
				ms_error("Error: Could not create pipe", cmd_struct);
		}
		pid = fork();
		if (pid == -1)
			ms_error("Error: Could not fork the process", cmd_struct);
		
		if (pid == 0)
		{
			redirect_child(old_fds, new_fds, cmd_struct, cmd_struct->command_nbr);
			if (check_builtin(cmd_struct))
				return ;
			run_execve(cmd_struct, cmd_struct->envp);
		}
		redirect_parent(old_fds, new_fds, cmd_struct, cmd_struct->command_nbr);
		cmd_struct = cmd_struct->next;
	}
}
