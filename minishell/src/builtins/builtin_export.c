/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:10:04 by raweber           #+#    #+#             */
/*   Updated: 2022/08/02 18:42:01 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Prints all environment variables properly formatted
static void	export_without_arguments(t_cmd_struct *cmd_struct)
{
	char	**export_output;
	int		i;

	export_output = sort_env(cmd_struct->env_clone, cmd_struct);
	i = 0;
	while (export_output[i])
	{
		export_output[i] = put_quotes(export_output[i]);
		export_output[i] = strjoin_free_second("declare -x ", export_output[i]);
		if (!ft_strnstr(export_output[i], "_=", ft_strlen(export_output[i])))
			ft_printf("%s\n", export_output[i]);
		i++;
	}
	i = 0;
	while (export_output[i])
		free(export_output[i++]);
	free(export_output);
}

// runs export command with arguments and checks for invalid input
static int	export_with_arguments(t_cmd_struct *cmd_struct)
{
	int	i;
	int	j;

	j = 1;
	while (cmd_struct->command_splitted[j])
	{
		if (!check_valid_export_variable(cmd_struct->command_splitted[j]))
			return (1);
		i = 0;
		while (i < cmd_struct->cur_env_size)
		{
			if (try_update_variables(cmd_struct, i, j))
				break ;
			i++;
		}
		if (i == cmd_struct->cur_env_size)
		{
			double_env_space(cmd_struct);
			export_with_arguments(cmd_struct);
		}
		j++;
	}
	return (0);
}

// Calls subfunctions depending on if one or more argument exist or not.
void	builtin_export(t_cmd_struct *cmd_struct)
{
	if (!cmd_struct->command_splitted[1])
		export_without_arguments(cmd_struct);
	else
		export_with_arguments(cmd_struct);
}

// checks if the export variable name is valid 
// valid: only alphanumeric + '_' allowed, may not start with number
int	check_valid_export_variable(char *cur_cmd)
{
	int	i;
	int	char_index;

	if (cur_cmd[0] == '-')
	{
		set_exit_status("Error: invalid option to minishell export\n", 2);
		return (0);
	}
	if (!valid_input_helper(cur_cmd, 0))
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
