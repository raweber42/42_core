/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:46:14 by raweber           #+#    #+#             */
/*   Updated: 2022/08/03 08:37:35 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Looks for PATH in the environment variables
// Splits them up into all possible paths
char	**get_paths(char **envp, t_cmd_struct *cmd_struct)
{
	int		i;
	char	**path_env;
	char	**sub_paths;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
		i++;
	if (!envp[i])
	{
		if (is_builtin(cmd_struct))
			return (NULL);
		set_exit_status("Error: No $PATH variable set, please set it!\n", 1);
		return (NULL);
	}
	path_env = ft_split(envp[i], '=');
	sub_paths = ft_split(path_env[1], ':');
	i = 0;
	while (sub_paths[i])
	{
		sub_paths[i] = strjoin_free_first(sub_paths[i], "/");
		i++;
	}
	free_double_array(path_env);
	return (sub_paths);
}

// checks if the command given is a full path (e.g. /bin/ls)
int	full_path_cmd(t_cmd_struct *cmd_struct)
{
	if (ft_strchr(cmd_struct->command_splitted[0], '/'))
	{
		if (access(cmd_struct->command_splitted[0], X_OK) == 0)
			cmd_struct->command_path = ft_strdup(
					cmd_struct->command_splitted[0]);
		return (1);
	}
	return (0);
}

// if no path is found, check for builtin and return
int	no_path_found(char **paths, t_cmd_struct *cmd_struct)
{
	if (paths == NULL)
	{
		if (is_builtin(cmd_struct))
			cmd_struct->command_path = ft_strdup("");
		return (1);
	}
	return (0);
}

// helper to find and set a valid command path in the struct
void	set_command_path(char **envp, t_cmd_struct *cmd_struct)
{
	char	**paths;
	int		i;

	paths = get_paths(envp, cmd_struct);
	if (no_path_found(paths, cmd_struct))
		return ;
	if (full_path_cmd(cmd_struct))
		return ;
	cmd_struct->command_path = ft_strjoin(paths[0],
			cmd_struct->command_splitted[0]);
	i = 0;
	while (paths[i] && (access(cmd_struct->command_path, X_OK) != 0))
	{
		free(cmd_struct->command_path);
		cmd_struct->command_path = ft_strjoin(paths[i++],
				cmd_struct->command_splitted[0]);
	}
	while (paths[i])
		i++;
	while (--i >= 0)
		free(paths[i]);
	free(paths);
}

// Joins two strings and free()'s the first one
char	*strjoin_free_first(char *str1, char *str2)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_string = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!new_string)
	{
		set_exit_status("Error: malloc failed in strjoin_free_first\n", 1);
		return (NULL);
	}
	while (str1[i])
	{
		new_string[i] = str1[i];
		i++;
	}
	free(str1);
	if (str2)
	{
		while (str2[j])
			new_string[i++] = str2[j++];
	}
	new_string[i] = '\0';
	return (new_string);
}
