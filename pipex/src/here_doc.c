/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:05:41 by raweber           #+#    #+#             */
/*   Updated: 2022/06/23 15:33:03 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	run_here_doc(t_pipex_list **argument_ll, char **argv)
{
	int		temp_doc;
	char	*buffer;

	temp_doc = open(".heredoc", O_TRUNC | O_CREAT | O_WRONLY, 0000644);
	if (temp_doc == -1)
		pipex_error("Error: Cannot create heredoc file", *argument_ll);
	while (1)
	{
		write(1, "heredoc> ", 9);
		buffer = get_next_line(STDIN_FILENO);
		if (ft_strncmp(argv[2], buffer, ft_strlen(argv[2])) == 0)
			break ;
		ft_putstr_fd(buffer, temp_doc);
		free(buffer);
	}
	free(buffer);
	close(temp_doc);
	(*argument_ll)->fd_infile = open(".heredoc", O_RDONLY);
	if ((*argument_ll)->fd_infile == -1)
	{
		unlink(".heredoc");
		pipex_error("Error: Could not open heredoc file", *argument_ll);
	}	
}
