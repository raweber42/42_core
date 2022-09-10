/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:30:08 by raweber           #+#    #+#             */
/*   Updated: 2022/08/04 15:12:29 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Sorts the environment variables alphabetically
char	**sort_env(char **env, t_cmd_struct *cmd_struct)
{
	char	*temp;
	char	**sorted;
	int		i;
	int		j;

	sorted = copy_env(env, cmd_struct);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < get_array_size(sorted) - 1)
	{
		j = 0;
		while (j < get_array_size(sorted) - 1)
		{
			if (ft_strncmp(sorted[j], sorted[j + 1], ft_strlen(sorted[j])) > 0)
			{
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (sorted);
}

void	strjoin_handler(char **splitted, int i, char *flag)
{
	if (get_array_size(splitted) == 1 && !flag)
		return ;
	if (i == 0)
		splitted[i] = strjoin_free_first(splitted[i], "=");
	if (i == 1)
		splitted[i] = strjoin_free_second("\"", splitted[i]);
	if (i >= 1 && splitted[i] && splitted[i + 1] != NULL)
		splitted[i] = strjoin_free_first(splitted[i], "=");
	if (i == 0 && splitted[i + 1] == NULL)
		splitted[i] = strjoin_free_first(splitted[i], "\"");
	if (splitted[i + 1] == NULL)
		splitted[i] = strjoin_free_first(splitted[i], "\"");
}

// Helper function for putting quotes around 
// the path of the given environment variable
char	*put_quotes(char *str)
{
	char	**splitted;
	char	*quoted;
	int		i;

	splitted = ft_split(str, '=');
	i = 0;
	while (splitted && splitted[i])
	{
		strjoin_handler(splitted, i, ft_strchr(str, '='));
		i++;
	}
	free(str);
	i = 0;
	while (splitted[i])
	{
		if (i == 0)
			quoted = splitted[i];
		else
			quoted = strjoin_free_both(quoted, splitted[i]);
		i++;
	}
	free(splitted);
	return (quoted);
}

// Doubles the environment space (in case the string array is full)
void	double_env_space(t_cmd_struct *cmd_struct)
{
	char	**temp_env;
	int		i;

	cmd_struct->cur_env_size *= 2;
	temp_env = malloc(sizeof(char *) * (cmd_struct->cur_env_size + 1));
	if (!temp_env)
	{
		set_exit_status("Error: malloc failed in double_env_space\n", 1);
		return ;
	}
	i = 0;
	while (cmd_struct->env_clone[i])
	{
		temp_env[i] = ft_strdup(cmd_struct->env_clone[i]);
		free(cmd_struct->env_clone[i]);
		i++;
	}
	cmd_struct->env_clone = temp_env;
}

// returns the index of the first appearance
// of a character in a given string or the string_length
// of the string if the character is not found
int	get_char_index(const char *s, int c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0 && s[i] != (char)c)
		i++;
	return (i);
}
