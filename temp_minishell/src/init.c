/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:03:02 by raweber           #+#    #+#             */
/*   Updated: 2022/07/10 17:24:41 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	init_linked_list(t_cmd_struct **cmd_struct, int argc, char **argv, char **envp)
// {
// 	return (0);
// }

// cur_env_size_multiple has to be set here to two!

int	get_env_size(char **envp)
{
	int	size;

	size = 0;
	while (envp && envp[size])
		size++;
	return (size);
}

char	**copy_env(char **envp, t_cmd_struct *cmd_struct)
{
	char	**copy;
	int		i;
	
	// copies double the amount in order to store more env variables in future
	copy = malloc(sizeof(char *) * (cmd_struct->cur_env_size + 1));
	
	if (!copy)
		return NULL;
	i = 0;
	while (envp[i]) //maybe change the condition to go up do cur_env_size
	{
		copy[i] = ft_strdup(envp[i]);
		i++;
	}
	while (i < (cmd_struct->cur_env_size))
		copy[i++] = NULL;
	return (copy);
}