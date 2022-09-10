/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:13:57 by raweber           #+#    #+#             */
/*   Updated: 2022/08/02 18:30:37 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
Searches for a environment variable and returns
an allocated string, if it exists.
*/
char	*get_env(t_cmd_struct *cmd_struct, char *str)
{
	char	*env_return;
	int		i;

	i = 0;
	env_return = NULL;
	while (str && cmd_struct->env_clone[i] && !ft_strnstr(
			cmd_struct->env_clone[i], str, ft_strlen(str)))
		i++;
	if (cmd_struct->env_clone[i] && ft_strnstr(cmd_struct->env_clone[i], str,
			ft_strlen(str)))
		env_return = ft_substr(cmd_struct->env_clone[i], 5,
				ft_strlen(cmd_struct->env_clone[i]) - 5);
	else
	{	
		set_exit_status("Error: Environment variable $HOME not found\n", 1);
		env_return = NULL;
	}
	return (env_return);
}

int	find_pwd_index(t_cmd_struct *cmd_struct)
{
	int	i;

	i = 0;
	while (cmd_struct->env_clone[i]
		&& !ft_strnstr(cmd_struct->env_clone[i], "PWD=", 4))
	{
		i++;
		if (cmd_struct->env_clone[i] && ft_strnstr(cmd_struct->env_clone[i],
				"OLDPWD=", 7))
			i++;
	}
	return (i);
}

// Updates the environment variables PWD and OLDPWD
static void	update_env(t_cmd_struct *cmd_struct, char *new_pwd_path,
				char *old_pwd_path)
{
	int	i;

	i = find_pwd_index(cmd_struct);
	if (cmd_struct->env_clone[i] && ft_strnstr(cmd_struct->env_clone[i],
			"PWD=", 4))
	{
		free(cmd_struct->env_clone[i]);
		cmd_struct->env_clone[i] = ft_strjoin("PWD=", new_pwd_path);
	}
	else
		old_pwd_path = NULL;
	i = 0;
	while (cmd_struct->env_clone[i] && !ft_strnstr(cmd_struct->env_clone[i],
			"OLDPWD", 6))
		i++;
	if (cmd_struct->env_clone[i] && ft_strnstr(cmd_struct->env_clone[i],
			"OLDPWD", 6))
	{
		free(cmd_struct->env_clone[i]);
		cmd_struct->env_clone[i] = ft_strjoin_zero_allowed("OLDPWD=",
				old_pwd_path);
	}
}

int	run_cd_home(t_cmd_struct *cmd_struct, char *old_path_ptr)
{
	char	*env_return;

	env_return = get_env(cmd_struct, "HOME=");
	if (!env_return)
		return (1);
	if (!cmd_struct->command_splitted[1])
	{
		if (env_return && chdir(env_return))
		{
			set_exit_status("Error while running <cd $HOME>\n", 1);
			free(old_path_ptr);
			free(env_return);
			return (1);
		}
		free(old_path_ptr);
		free(env_return);
		return (1);
	}
	return (0);
}

/*
Changes the current working directory to the given
absolute or relative path. If no argument given,
the $HOME path is taken as default argument
*/
void	builtin_cd(t_cmd_struct *cmd_struct)
{
	char	*old_path_ptr;
	char	*new_path_ptr;

	old_path_ptr = getcwd(NULL, 0);
	if (run_cd_home(cmd_struct, old_path_ptr))
		return ;
	if (chdir(cmd_struct->command_splitted[1]))
	{
		if (cmd_struct->command_splitted[1][0] == '-')
			set_exit_status("Error: invalid option for cd\n", 1);
		else
			set_exit_status("Error: No such file or directory\n", 1);
		free(old_path_ptr);
		return ;
	}
	new_path_ptr = getcwd(NULL, 0);
	update_env(cmd_struct, new_path_ptr, old_path_ptr);
	free(old_path_ptr);
	free(new_path_ptr);
}
