/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:17:42 by raweber           #+#    #+#             */
/*   Updated: 2022/08/02 10:38:59 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// helper for validity parsing of command
int	valid_input_helper_unset(char *cur_cmd, int i)
{
	if (!i)
	{
		if (!ft_isalpha(cur_cmd[i]) && !ft_strchr(cur_cmd, '_')
			&& !ft_strchr(cur_cmd, '\"') && !ft_strchr(cur_cmd, '\''))
		{
			set_exit_status("Error: invalid input to minishell unset\n", 1);
			return (0);
		}
		return (1);
	}
	else
	{
		if (!ft_isalnum(cur_cmd[i]) && !ft_strchr(cur_cmd, '_')
			&& !ft_strchr(cur_cmd, '\"') && !ft_strchr(cur_cmd, '\''))
		{
			set_exit_status("Error: invalid input to minishell unset\n", 1);
			return (0);
		}
		return (1);
	}
}

// checks if the export variable name is valid
// valid: only alnum + '_' allowed, may not start with number
int	check_valid_unset_variable(char *cur_cmd)
{
	int	i;
	int	char_index;

	if (cur_cmd[0] == '-')
	{
		set_exit_status("Error: invalid option to minishell unset\n", 2);
		return (0);
	}	
	if (!valid_input_helper_unset(cur_cmd, 0))
		return (0);
	i = 1;
	char_index = get_char_index(cur_cmd, '=');
	while (cur_cmd[i] && i < char_index)
	{
		if (!valid_input_helper(cur_cmd, i++))
			return (0);
	}
	return (1);
}

void	move_array_members(t_cmd_struct *cmd_struct, int i)
{
	while (cmd_struct->env_clone[i + 1])
	{
		free(cmd_struct->env_clone[i]);
		cmd_struct->env_clone[i] = ft_strdup(
				cmd_struct->env_clone[i + 1]);
		i++;
	}
	free(cmd_struct->env_clone[i]);
	cmd_struct->env_clone[i] = NULL;
}

/*
Unsets environment variables from the minishell env_clone
If the give argument(s) are not environment variables,
nothing happens. If a variable is unset, all the others
are moved so that the list does not have any empty places
*/
void	builtin_unset(t_cmd_struct *cmd_struct)
{
	int	i;
	int	j;

	j = 1;
	while (cmd_struct->command_splitted[j])
	{
		if (!check_valid_unset_variable(cmd_struct->command_splitted[j]))
			return ;
		i = 0;
		while (cmd_struct->env_clone[i] && ft_strncmp(cmd_struct->env_clone[i],
				cmd_struct->command_splitted[j],
				ft_strlen(cmd_struct->command_splitted[j])))
			i++;
		if (cmd_struct->env_clone[i] && !ft_strncmp(cmd_struct->env_clone[i],
				cmd_struct->command_splitted[j],
				ft_strlen(cmd_struct->command_splitted[j])))
		{
			move_array_members(cmd_struct, i);
		}
		j++;
	}
}
