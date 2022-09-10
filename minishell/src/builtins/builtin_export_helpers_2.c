/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_helpers_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:14:23 by raweber           #+#    #+#             */
/*   Updated: 2022/08/02 18:41:13 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// helper for validity parsing of command
int	valid_input_helper(char *cur_cmd, int i)
{
	if (!i)
	{
		if (!ft_isalpha(cur_cmd[i]) && !ft_strchr(cur_cmd, '_')
			&& !ft_strchr(cur_cmd, '\"') && !ft_strchr(cur_cmd, '\''))
		{
			set_exit_status("Error: invalid input to minishell export\n", 1);
			return (0);
		}
		return (1);
	}
	else
	{
		if (!ft_isalnum(cur_cmd[i]) && !ft_strchr(cur_cmd, '_')
			&& !ft_strchr(cur_cmd, '\"') && !ft_strchr(cur_cmd, '\''))
		{
			set_exit_status("Error: invalid input to minishell export\n", 1);
			return (0);
		}
		return (1);
	}
}

// trims away all single and double quotes from a given string.
char	*trim_quotes(char *string)
{
	char	*trimmed;
	int		i;
	int		j;

	trimmed = malloc(ft_strlen(string) + 1);
	if (!trimmed)
	{
		set_exit_status("Error: malloc failed in trim_quotes\n", 1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (string[i])
	{
		if (string[i] != '\"' && string[i] != '\'')
			trimmed[j++] = string[i];
		i++;
	}
	trimmed[j] = 0;
	return (trimmed);
}

// helper for updating existing variables in env
int	try_update_variables(t_cmd_struct *cmd_struct, int i, int j)
{
	if (check_if_export_exists(&cmd_struct->env_clone[i],
			cmd_struct->command_splitted[j]))
		return (1);
	if (cmd_struct->env_clone[i] == NULL)
	{
		cmd_struct->env_clone[i] = trim_quotes(
				cmd_struct->command_splitted[j]);
		return (1);
	}
	return (0);
}

int	existing_equalsign_check(char **env_var, char *export_var, int equal_pos)
{
	if (!ft_strncmp(*env_var, export_var, equal_pos + 1))
	{
		if (ft_strchr(export_var, '='))
		{
			free(*env_var);
			*env_var = trim_quotes(export_var);
		}
		return (1);
	}
	if (!ft_strncmp(*env_var, export_var, equal_pos))
	{
		if (export_var[equal_pos] == '=')
		{
			free(*env_var);
			*env_var = trim_quotes(export_var);
			return (1);
		}
		else if (export_var[equal_pos] == 0)
			return (1);
		return (0);
	}
	return (0);
}

/*
Checks if the value passed to export already exists and
updates it if that is the case.
*/
int	check_if_export_exists(char **env_var, char *export_var)
{
	unsigned int	equalsign_pos;

	equalsign_pos = get_char_index(*env_var, '=');
	if (equalsign_pos)
	{
		if (existing_equalsign_check(env_var, export_var, equalsign_pos) == 1)
			return (1);
		else
			return (0);
	}
	else if ((ft_strlen(*env_var) >= ft_strlen(export_var) - 1)
		&& !ft_strncmp(*env_var, export_var, ft_strlen(*env_var)))
	{
		if (get_char_index(export_var, '='))
		{
			free(*env_var);
			*env_var = trim_quotes(export_var);
		}
		return (1);
	}
	return (0);
}
