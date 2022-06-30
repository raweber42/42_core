/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:37:45 by raweber           #+#    #+#             */
/*   Updated: 2022/06/23 08:53:19 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// redirects the child STDIN/STDOUT to the pipe
// or to the infile/outfile
void	redirect_child(int *old_fds, int *new_fds,
			t_pipex_list *argument_ll, int previous_command_exists)
{
	if (previous_command_exists)
	{	
		dup2(old_fds[0], 0);
		close(old_fds[0]);
		close(old_fds[1]);
	}
	else
	{
		dup2(argument_ll->fd_infile, 0);
		close(argument_ll->fd_infile);
	}
	if (argument_ll->next)
	{
		close(new_fds[0]);
		dup2(new_fds[1], 1);
		close(new_fds[1]);
	}
	else
	{
		close(new_fds[0]);
		argument_ll->fd_outfile = get_fd_outfile(argument_ll);
		dup2(argument_ll->fd_outfile, 1);
		close(argument_ll->fd_outfile);
		close(new_fds[1]);
	}
}

// redirects the parent STDIN/STDOUT to the pipe
void	redirect_parent(int *old_fds, int *new_fds,
			t_pipex_list *argument_ll, int previous_command_exists)
{
	if (previous_command_exists)
	{
		close(old_fds[1]);
		close(old_fds[0]);
	}
	else
		close(argument_ll->fd_infile);
	if (argument_ll->next)
	{
		old_fds[0] = new_fds[0];
		old_fds[1] = new_fds[1];
	}
}
