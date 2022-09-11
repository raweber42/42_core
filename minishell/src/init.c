/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:03:02 by raweber           #+#    #+#             */
/*   Updated: 2022/07/31 09:02:51 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// 🎃@ALINA: cur_env_size_multiple has to be set here to two!!!🎃

// Returns the amount of strings (=size) of the envp variable
int	get_array_size(char **envp)
{
	int	size;

	size = 0;
	while (envp && envp[size])
		size++;
	return (size);
}

/* 
Copies the given envp variable into a newly allocated string array
and returns the ladder.
*/
char	**copy_env(char **envp, t_cmd_struct *cmd_struct)
{
	char	**copy;
	int		i;
	int		old_pwd_exists;

	copy = malloc(sizeof(char *) * (cmd_struct->cur_env_size + 1));
	if (!copy)
	{
		set_exit_status("Error: malloc failed in copy_env\n", 1);
		return (NULL);
	}
	i = 0;
	old_pwd_exists = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "OLDPWD", 6))
			old_pwd_exists = 1;
		copy[i] = ft_strdup(envp[i]);
		i++;
	}
	if (!old_pwd_exists)
		copy[i++] = ft_strdup("OLDPWD");
	while (i < (cmd_struct->cur_env_size))
		copy[i++] = NULL;
	return (copy);
}
