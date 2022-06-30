/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:46:14 by raweber           #+#    #+#             */
/*   Updated: 2022/06/23 16:47:03 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// Looks for PATH in the environment variables
// Splits them up into all possible paths
char	**get_paths(char **envp)
{
	int		i;
	char	**path_env;
	char	**sub_paths;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
		i++;
	path_env = ft_split(envp[i], '=');
	sub_paths = ft_split(path_env[1], ':');
	i = 0;
	while (sub_paths[i])
	{
		sub_paths[i] = pipex_strjoin(sub_paths[i], "/");
		i++;
	}
	i = 0;
	while (path_env[i])
	{
		free(path_env[i++]);
	}
	free (path_env);
	return (sub_paths);
}

// opens the file for reading and returns the descriptor
int	get_fd_infile(char *filename, t_pipex_list *argument_ll)
{
	int	fd_infile;

	fd_infile = open(filename, O_RDONLY);
	if (fd_infile == -1)
		pipex_error("Error: Cannot open input file for reading", argument_ll);
	return (fd_infile);
}

// opens the file for writing and returns the descriptor
int	get_fd_outfile(t_pipex_list *argument_ll)
{
	int	fd_outfile;

	if (argument_ll->here_doc)
		fd_outfile = open(argument_ll->filename,
				O_RDWR | O_APPEND | O_CREAT, 0666);
	else
		fd_outfile = open(argument_ll->filename,
				O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (fd_outfile == -1)
		pipex_error("Error: Cannot open output file for writing", argument_ll);
	return (fd_outfile);
}

// helper to find and set a valid command path in the struct
void	set_command_path(char **envp, t_pipex_list *node)
{
	char	**paths;
	int		i;

	paths = get_paths(envp);
	node->command_path = ft_strjoin(paths[0], node->command_splitted[0]);
	i = 0;
	while (paths[i] && (access(node->command_path, X_OK) != 0))
	{
		free(node->command_path);
		node->command_path = ft_strjoin(paths[i++], node->command_splitted[0]);
	}
	while (paths[i])
		i++;
	i--;
	while (i >= 0)
		free(paths[i--]);
	free(paths);
}

// restructured strjoin which frees the first string
char	*pipex_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_str == 0)
		return (0);
	while (s1[i] != 0)
	{
		new_str[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j] != 0)
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = 0;
	return (new_str);
}
