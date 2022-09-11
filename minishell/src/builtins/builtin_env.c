/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:38:28 by raweber           #+#    #+#             */
/*   Updated: 2022/08/02 10:38:46 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	builtin_env(t_cmd_struct *cmd_struct)
{
	int		i;

	i = 0;
	while (cmd_struct->env_clone[i] && i < cmd_struct->cur_env_size)
	{
		if (!ft_strncmp(cmd_struct->env_clone[i], "_=", 2))
		{
			free(cmd_struct->env_clone[i]);
			cmd_struct->env_clone[i] = ft_strdup("_=usr/bin/env");
		}
		if (ft_strchr(cmd_struct->env_clone[i], '='))
			ft_printf("%s\n", cmd_struct->env_clone[i]);
		i++;
	}
}
