/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:30:54 by raweber           #+#    #+#             */
/*   Updated: 2022/08/05 07:53:34 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// checks if the given command is a builtin
int	is_builtin(t_cmd_struct *cmd_struct)
{
	if (!ft_strncmp(cmd_struct->command_splitted[0], "cd", 3))
		return (1);
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "export", 7))
		return (1);
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "unset", 6))
		return (1);
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "exit", 5))
		return (1);
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "echo", 5))
		return (1);
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "pwd", 4))
		return (1);
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "env", 4))
		return (1);
	return (0);
}

// Checks for built_in commands that cannot be run in a child and executes them.
// if the commands in here are piped, they are not executed
int	check_builtin_1(t_cmd_struct *cmd_struct)
{
	signal_not_interactive();
	if (!ft_strncmp(cmd_struct->command_splitted[0], "cd", 3))
	{	
		if (cmd_struct->next)
			return (1);
		builtin_cd(cmd_struct);
		return (1);
	}
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "export", 7))
	{
		if (cmd_struct->next)
			return (1);
		builtin_export(cmd_struct);
		return (1);
	}
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "unset", 6))
	{
		if (cmd_struct->next)
			return (1);
		builtin_unset(cmd_struct);
		return (1);
	}
	else if (exit_helper(cmd_struct))
		return (1);
	return (0);
}

// Checks if the currently run command is a builtin and executes it, if so.
int	check_builtin_2(t_cmd_struct *cmd_struct)
{
	if (!ft_strncmp(cmd_struct->command_splitted[0], "echo", 5))
	{
		builtin_echo(cmd_struct);
		return (1);
	}
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "pwd", 4))
	{
		if (cmd_struct->command_splitted[1]
			&& cmd_struct->command_splitted[1][0] == '-')
		{
			set_exit_status("pwd: invalid option\n", 1);
			return (1);
		}
		builtin_pwd();
		return (1);
	}
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "env", 4))
	{
		try_env(cmd_struct);
		return (1);
	}
	return (0);
}

int	exit_helper(t_cmd_struct *cmd_struct)
{
	if (!ft_strncmp(cmd_struct->command_splitted[0], "exit", 5))
	{
		if (cmd_struct->next)
			return (1);
		builtin_exit(cmd_struct);
		return (1);
	}
	return (0);
}

void	try_env(t_cmd_struct *cmd_struct)
{
	if (get_array_size(cmd_struct->command_splitted) > 1)
	{
		set_exit_status("Error: minishell env doesn't take arguments\n", 1);
		return ;
	}
	builtin_env(cmd_struct);
	return ;
}
