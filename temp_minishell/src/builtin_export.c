/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:10:04 by raweber           #+#    #+#             */
/*   Updated: 2022/07/11 12:27:43 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
	while (i < get_env_size(sorted) - 1)
	{
		j = 0;
		while (j < get_env_size(sorted) - 1)
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
	//free(sorted[i]); // is this the right one freed? maybe leak-anfällig?
	return (sorted);
}

// secured version of stringjoin to prevent memory leaks
// works also as strdup if the first argument is zero
char	*strjoin_free_second(char *str1, char *str2)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_string = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (new_string == 0)
		return (NULL);
	while (str1 && str1[i])
	{
		new_string[i] = str1[i];
		i++;
	}
	if (str2)
	{
		while (str2[j])
			new_string[i++] = str2[j++];
		free(str2);
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*strjoin_free_first(char *str1, char *str2)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_string = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (new_string == 0)
		return (NULL);
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

char	*strjoin_free_both(char *str1, char *str2)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_string = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (new_string == 0)
		return (NULL);
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
	free(str2);
	new_string[i] = '\0';
	return (new_string);
}

char	*put_quotes(char *str)
{
	char	**splitted;
	char	*quoted;
	int		i;

	splitted = ft_split(str, '=');
	free(str);
	i = 0;
	while (splitted[i])
	{
		if (i == 0)
			splitted[i] = strjoin_free_first(splitted[i], "=");
		if (i == 1)
			splitted[i] = strjoin_free_second("\"", splitted[i]);
		// else if (splitted[i + 1] != NULL)
		// 	splitted[i] = strjoin_free_both(splitted[i], splitted[i + 1]);
		if (splitted[i + 1] == NULL)
			splitted[i] = strjoin_free_first(splitted[i], "\"");
		i++;
	}
	i = 0;
	while (splitted[i])
	{
		//printf("current: %s\n", quoted);
		if (i == 0)
			quoted = splitted[i]; //is this right???
		else
			quoted = strjoin_free_both(quoted, splitted[i]);
		i++;
	}
	free(splitted);
	return (quoted);
}

void	export_without_arguments(t_cmd_struct *cmd_struct)
{
	char	**export_output;
	int		i;

	export_output = sort_env(cmd_struct->env_clone, cmd_struct);
	i = 0;
	
	while (export_output[i]) //check this again! there is more allocated then it should
	{
		export_output[i] = put_quotes(export_output[i]);
		export_output[i] = strjoin_free_second("declare -x ", export_output[i]);
		ft_printf("%s\n", export_output[i]);
		i++;
	}
	
	i = 0;
	while (export_output[i])
		free(export_output[i++]);
	free(export_output);
}

void	double_env_space(t_cmd_struct *cmd_struct)
{
	char	**temp_env;
	int		i;
	
	cmd_struct->cur_env_size *= 2;
	temp_env = malloc(cmd_struct->cur_env_size + 1);
	if (!temp_env)
		ms_error("Error while allocating memory for temp_env", cmd_struct);
	ft_memcpy(temp_env, cmd_struct->env_clone, (cmd_struct->cur_env_size / 2));
	i = 0;
	while (cmd_struct->env_clone[i])
		free(cmd_struct->env_clone[i++]);
	cmd_struct->env_clone = temp_env;	
}

void	export_with_arguments(t_cmd_struct *cmd_struct)
{
	int	i;

	i = 0;
	while (i < cmd_struct->cur_env_size)
	{
		if (cmd_struct->env_clone[i] == NULL)
		{
			cmd_struct->env_clone[i] = ft_strdup(cmd_struct->command_splitted[1]);
			return ;
		}
		i++;
	}
	if (i == cmd_struct->cur_env_size) //---->>>>> THIS segfaults!
	{
		double_env_space(cmd_struct);
		export_with_arguments(cmd_struct); // does this recursion work?
	}
}

void	builtin_export(t_cmd_struct *cmd_struct)
{
	if (!cmd_struct->command_splitted[1])
		export_without_arguments(cmd_struct);
	else
		export_with_arguments(cmd_struct);
}

// int main(int argc, char **argv, char **envp)
// {
// 	t_cmd_struct *cmd_struct;
	
// 	cmd_struct =  malloc(sizeof(t_cmd_struct));
// 	cmd_struct->command_splitted =  malloc(2 * sizeof(char *));
// 	cmd_struct->command_splitted[0] = "export";
// 	cmd_struct->command_splitted[1] = "TESTVAR=testvar";
// 	cmd_struct->cur_env_size = get_env_size(envp) * 2;
// 	cmd_struct->env_clone = copy_env(envp, cmd_struct);
	
// 	builtin_export(cmd_struct);
// 	// cmd_struct->command_splitted[1] = NULL;
// 	// builtin_export(cmd_struct);
// 	//printf("HERE\n");
	
// 	// int i = 0;
// 	// while (cmd_struct->env_clone[i])
// 	// {
// 	// 	printf("%s\n", cmd_struct->env_clone[i++]);
// 	// }
	
// 	argc = 0;
// 	argv = NULL;

// 	free(cmd_struct->command_splitted);
// 	int i = 0;
// 	while (cmd_struct->env_clone[i])
// 		free(cmd_struct->env_clone[i++]);
// 	free(cmd_struct->env_clone);
// 	free(cmd_struct);
// 	return (0);
// }
