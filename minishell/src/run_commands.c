/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:00:44 by raweber           #+#    #+#             */
/*   Updated: 2022/08/05 07:53:09 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// opens a pipe for a builtin command and 'redirects' the parent, if flag is set
int	pipe_builtin(t_cmd_struct *cmd_struct, int *old_fds, int *new_fds, int flag)
{
	if (cmd_struct->next)
	{
		if (pipe(new_fds))
		{
			set_exit_status("Error: Could not create pipe\n", 1);
			return (0);
		}
		if (flag)
			redirect_parent(old_fds, new_fds, cmd_struct);
	}
	return (1);
}

// executes the child process
void	child_execution(int pid, int *old_fds, int *new_fds,
			t_cmd_struct *cmd_struct)
{
	if (pid == 0)
	{
		signal_child_active();
		redirect_child(old_fds, new_fds, cmd_struct,
			cmd_struct->command_nbr);
		if (check_builtin_2(cmd_struct))
			exit(g_exit_status);
		if (access(cmd_struct->command_path, X_OK) != 0)
		{
			set_exit_status("Error: command not found\n", 127);
			exit(127);
		}
		else
		{
			execve(cmd_struct->command_path,
				cmd_struct->command_splitted, cmd_struct->env_clone);
			set_exit_status("Error: command not found\n", 127);
		}
	}
}

// waits for all child processes to finish
void	wait_for_children(int pid, int *waitpid_status)
{
	while (pid > 0)
		pid = wait(waitpid_status);
	if (WIFEXITED(*waitpid_status))
		g_exit_status = WEXITSTATUS(*waitpid_status);
}

// executes child and redirects child and parent
void	execute_and_redirect(int pid, int *old_fds, int *new_fds,
			t_cmd_struct *cmd_struct)
{
	child_execution(pid, old_fds, new_fds, cmd_struct);
	redirect_parent(old_fds, new_fds, cmd_struct);
}

// creates childs, runs commands in them and redirects
// input and output for parent and children
void	run_commands(t_cmd_struct *cmd_struct)
{
	int		pid;
	int		new_fds[2];
	int		old_fds[2];
	int		waitpid_status;

	pid = 0;
	while (cmd_struct)
	{
		if (check_builtin_1(cmd_struct))
		{
			if (!pipe_builtin(cmd_struct, old_fds, new_fds, 1))
				return ;
			cmd_struct = cmd_struct->next;
			continue ;
		}
		else
			if (!pipe_builtin(cmd_struct, old_fds, new_fds, 0))
				return ;
		pid = fork();
		if (fork_failed(pid))
			return ;
		execute_and_redirect(pid, old_fds, new_fds, cmd_struct);
		cmd_struct = cmd_struct->next;
	}
	wait_for_children(pid, &waitpid_status);
}
