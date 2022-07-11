/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:19:31 by raweber           #+#    #+#             */
/*   Updated: 2022/07/06 09:14:17 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// redirects the child STDIN/STDOUT to the pipe
// or to the infile/outfile
void	redirect_child(int *old_fds, int *new_fds,
			t_cmd_struct *cmd_struct, int previous_command_exists)
{
	//printf("previous exists: %d\n", previous_command_exists);
	if (previous_command_exists)
	{	
		dup2(old_fds[0], 0);
		close(old_fds[0]);
		close(old_fds[1]);
	}
	else
	{
		dup2(cmd_struct->fd_infile, 0);
		close(cmd_struct->fd_infile);
	}
	if (cmd_struct->next)
	{
		close(new_fds[0]);
		dup2(new_fds[1], 1); // if commented out, child goes always to stdout
		close(new_fds[1]);
	}
	else
	{
		close(new_fds[0]);
		//cmd_struct->fd_outfile = get_fd_outfile(cmd_struct); ##->>> handle this later!
		dup2(cmd_struct->fd_outfile, 1);
		//close(cmd_struct->fd_outfile); // COMMENTED OUT! Only shouldnt be done if outfile is stdout!
		close(new_fds[1]);
		
	}
	// printf("TEST in child redirect\n");
}

// redirects the parent STDIN/STDOUT to the pipe
void	redirect_parent(int *old_fds, int *new_fds,
			t_cmd_struct *cmd_struct, int previous_command_exists)
{
	if (previous_command_exists)
	{
		close(old_fds[1]);
		close(old_fds[0]);
	}
	else
		close(cmd_struct->fd_infile);
	if (cmd_struct->next)
	{
		old_fds[0] = new_fds[0];
		old_fds[1] = new_fds[1];
	}
	// printf("TEST in parent redirect\n");
}
