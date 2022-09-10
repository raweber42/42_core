/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:22:16 by raweber           #+#    #+#             */
/*   Updated: 2022/08/02 10:38:44 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// helper function that handles echo without arguments
static int	echo_no_args(t_cmd_struct *cmd_struct)
{
	if (!cmd_struct->command_splitted[1])
	{
		ft_printf("\n");
		return (1);
	}
	else if (!ft_strncmp(cmd_struct->command_splitted[1], "-n", 3)
		&& !cmd_struct->command_splitted[2])
		return (1);
	return (0);
}

// runs echo printing with newline appended
static void	echo_no_newline(t_cmd_struct *cmd_struct)
{
	int	i;

	i = 2;
	while (cmd_struct->command_splitted[i])
	{
		if (i > 2)
			ft_printf(" ");
		ft_printf("%s", cmd_struct->command_splitted[i++]);
	}
}

// runs echo printing without newline appended
static void	echo_with_newline(t_cmd_struct *cmd_struct)
{
	int	i;

	i = 1;
	while (cmd_struct->command_splitted[i])
	{
		if (i > 1)
			ft_printf(" ");
		ft_printf("%s", cmd_struct->command_splitted[i++]);
	}
	ft_printf("\n");
}

/*
Prints the given argument(s), concatenated with a \n, to STDOUT.
If the '-n' flag is given, no newline is printed.
*/
void	builtin_echo(t_cmd_struct *cmd_struct)
{
	if (echo_no_args(cmd_struct))
		return ;
	if (cmd_struct->command_splitted[1]
		&& !ft_strncmp(cmd_struct->command_splitted[1], "-n", 3))
	{
		echo_no_newline(cmd_struct);
	}
	else
	{
		echo_with_newline(cmd_struct);
	}
}
