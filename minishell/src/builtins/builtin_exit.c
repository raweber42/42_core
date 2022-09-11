/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:10:15 by raweber           #+#    #+#             */
/*   Updated: 2022/08/02 18:31:03 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
Exits the minishell with a given value as exit value.
Default exit value is 0
Uses hardened atoi (returns -2147483648 if not a number)
*/
void	builtin_exit(t_cmd_struct *cmd_struct)
{
	if (cmd_struct->command_splitted[1])
		g_exit_status = ft_atoi(cmd_struct->command_splitted[1]);
	else
		g_exit_status = 0;
	ft_printf("exit\n");
	if (g_exit_status == -2147483648)
	{
		ft_putstr_fd("bash: exit: numeric argument required\n", 2);
		g_exit_status = 255;
	}
	else if (cmd_struct->command_splitted[1] && cmd_struct->command_splitted[2])
	{
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
		g_exit_status = 1;
		return ;
	}
	clean_up(cmd_struct);
	exit(g_exit_status);
}
