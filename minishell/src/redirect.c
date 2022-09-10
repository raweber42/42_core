/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:19:31 by raweber           #+#    #+#             */
/*   Updated: 2022/08/03 08:22:09 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	previous_exists_check(int *old_fds, t_cmd_struct *cmd_struct,
									int previous_command_exists)
{
	if (previous_command_exists)
	{	
		dup2(old_fds[READ_END], STDIN_FILENO);
		close(old_fds[READ_END]);
		close(old_fds[WRITE_END]);
	}
	else
	{
		if (cmd_struct->fd_infile != 0)
		{
			dup2(cmd_struct->fd_infile, STDIN_FILENO);
			close(cmd_struct->fd_infile);
		}
	}
}

// redirects the child STDIN/STDOUT to the pipe
// or to the infile/outfile
void	redirect_child(int *old_fds, int *new_fds,
			t_cmd_struct *cmd_struct, int previous_command_exists)
{
	previous_exists_check(old_fds, cmd_struct, previous_command_exists);
	if (cmd_struct->next)
	{
		close(new_fds[READ_END]);
		dup2(new_fds[WRITE_END], STDOUT_FILENO);
		close(new_fds[WRITE_END]);
	}
	else
	{
		close(new_fds[READ_END]);
		if (cmd_struct->fd_outfile != 1)
		{
			dup2(cmd_struct->fd_outfile, STDOUT_FILENO);
			close(cmd_struct->fd_outfile);
		}
		close(new_fds[WRITE_END]);
	}
}

// redirects the parent STDIN/STDOUT to the pipe
void	redirect_parent(int *old_fds, int *new_fds,
			t_cmd_struct *cmd_struct)
{
	if (cmd_struct->command_nbr)
	{
		close(old_fds[1]);
		close(old_fds[0]);
	}
	else
	{
		if (cmd_struct->fd_infile != 0)
			close(cmd_struct->fd_infile);
	}
	if (cmd_struct->next)
	{
		old_fds[0] = new_fds[0];
		old_fds[1] = new_fds[1];
	}
}
