/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:17:42 by raweber           #+#    #+#             */
/*   Updated: 2022/07/11 12:27:35 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	builtin_unset(t_cmd_struct *cmd_struct)
{
	int	i;

	i = 0;
	
	//printf("command-splitted: %s\n", cmd_struct->command_splitted[1]);
	while (ft_strncmp(cmd_struct->env_clone[i], cmd_struct->command_splitted[1], ft_strlen(cmd_struct->command_splitted[1]) - 1))
	{
		//printf("env_clone_string: %s\n", cmd_struct->env_clone[i]);
		i++;
	}
	if (!ft_strncmp(cmd_struct->env_clone[i], cmd_struct->command_splitted[1], ft_strlen(cmd_struct->command_splitted[1]) - 1))
	{
		// free the env variable and move all others one position down
		// to prevent NULL in middle of the array!	
		while (cmd_struct->env_clone[i + 1])
		{
			free(cmd_struct->env_clone[i]);
			cmd_struct->env_clone[i] = ft_strdup(cmd_struct->env_clone[i + 1]);
			i++;
		}
		free(cmd_struct->env_clone[i]); // is this right?
		cmd_struct->env_clone[i] = NULL;
	}
}

// //removes! fine!
// int main(int argc, char **argv, char **envp)
// {
// 	t_cmd_struct *cmd_struct;
	
// 	cmd_struct =  malloc(sizeof(t_cmd_struct));
// 	cmd_struct->command_splitted =  malloc(2 * sizeof(char *));
// 	cmd_struct->command_splitted[0] = "unset";
// 	cmd_struct->command_splitted[1] = "TESTVAR";
// 	cmd_struct->cur_env_size = get_env_size(envp) * 2;
// 	cmd_struct->env_clone = copy_env(envp, cmd_struct);
	
// 	builtin_unset(cmd_struct);
// 	// cmd_struct->command_splitted[1] = NULL;
// 	// builtin_export(cmd_struct);
// 	//printf("HERE\n");
	
// 	int i = 0;
// 	while (cmd_struct->env_clone[i])
// 	{
// 		printf("%s\n", cmd_struct->env_clone[i++]);
// 	}
	
// 	argc += 0;
// 	argv[2] = NULL;

// 	// free(cmd_struct->command_splitted);
// 	// i = 0;
// 	// while (cmd_struct->env_clone[i])
// 	// 	free(cmd_struct->env_clone[i++]);
// 	// free(cmd_struct->env_clone);
// 	// free(cmd_struct);
// 	return (0);
// }
