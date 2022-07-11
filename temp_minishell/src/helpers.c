/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:46:14 by raweber           #+#    #+#             */
/*   Updated: 2022/07/06 09:25:38 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
int	get_fd_infile(char *filename, t_cmd_struct *cmd_struct)
{
	int	fd_infile;

	fd_infile = open(filename, O_RDONLY);
	if (fd_infile == -1)
		ms_error("Error: Cannot open input file for reading", cmd_struct);
	return (fd_infile);
}

// opens the file for writing and returns the descriptor
int	get_fd_outfile(t_cmd_struct *cmd_struct)
{
	int	fd_outfile;

	if (cmd_struct->here_doc)
		fd_outfile = open(cmd_struct->filename,
				O_RDWR | O_APPEND | O_CREAT, 0666);
	else
		fd_outfile = open(cmd_struct->filename,
				O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (fd_outfile == -1)
		ms_error("Error: Cannot open output file for writing", cmd_struct);
	return (fd_outfile);
}

// helper to find and set a valid command path in the struct
void	set_command_path(char **envp, t_cmd_struct *cmd_struct)
{
	char	**paths;
	int		i;

	paths = get_paths(envp);
	cmd_struct->command_path = ft_strjoin(paths[0], cmd_struct->command_splitted[0]);
	i = 0;
	while (paths[i] && (access(cmd_struct->command_path, X_OK) != 0))
	{
		free(cmd_struct->command_path);
		cmd_struct->command_path = ft_strjoin(paths[i++], cmd_struct->command_splitted[0]);
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
