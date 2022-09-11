/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_redir_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:21:30 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/03 20:12:37 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	handle_in_redir(int *fd_infile, char *filename)
{
	if (*fd_infile != 0)
		close(*fd_infile);
	*fd_infile = open(filename, O_RDONLY);
	if (*fd_infile == -1)
		return (return_with_strerror(errno));
	return (0);
}

int	handle_out_redir(int *fd_outfile, char *filename)
{
	if (*fd_outfile != 1)
		close(*fd_outfile);
	*fd_outfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (*fd_outfile == -1)
		return (return_with_strerror(errno));
	return (0);
}

int	handle_append(int *fd_outfile, char *filename)
{
	if (*fd_outfile != 1)
		close(*fd_outfile);
	*fd_outfile = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (*fd_outfile == -1)
		return (return_with_strerror(errno));
	return (0);
}

int	handle_heredoc(int *fd_infile, char *deli)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (*fd_infile != 0)
		close(*fd_infile);
	if (pipe(pipe_fd) == -1)
		return (return_with_strerror(errno));
	pid = fork();
	if (pid == -1)
		return (return_with_strerror(errno));
	signal_heredoc_parent();
	if (pid == 0)
		heredoc_loop(pipe_fd, deli);
	if (pid > 0)
	{
		if (heredoc_parent(pid, pipe_fd) == -1)
			return (-1);
		*fd_infile = pipe_fd[0];
	}
	close(pipe_fd[1]);
	return (0);
}

void	heredoc_loop(int *pipe_fd, char *deli)
{
	char	*ret;

	close(pipe_fd[0]);
	while (23)
	{
		signal_heredoc_child();
		ret = readline("> ");
		if (!ret)
			exit_heredoc(pipe_fd[1]);
		if (ft_strncmp(ret, deli, ft_strlen(deli)) == 0)
		{
			free(ret);
			exit_heredoc(pipe_fd[1]);
		}
		write(pipe_fd[1], ret, ft_strlen(ret));
		write(pipe_fd[1], "\n", 1);
		free(ret);
	}
}
