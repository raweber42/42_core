/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_heredoc_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:28:04 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/03 20:00:23 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	signal_heredoc_child(void)
{
	signal(SIGINT, &quit_heredoc);
	signal(SIGQUIT, SIG_IGN);
}

void	quit_heredoc(int signal)
{
	if (signal == SIGINT)
		exit(23);
}

int	exit_heredoc(int pipe_fd)
{
	close(pipe_fd);
	exit (0);
}

void	signal_heredoc_parent(void)
{
	signal(SIGQUIT, &interactive_sigint);
	signal(SIGINT, SIG_IGN);
}

int	heredoc_parent(pid_t pid, int *pipe_fd)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 23)
		{
			close(pipe_fd[1]);
			if (pipe(pipe_fd) == -1)
				return (return_with_strerror(errno));
			close(pipe_fd[1]);
		}
	}
	return (0);
}
