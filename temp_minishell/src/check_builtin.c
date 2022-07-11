/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:30:54 by raweber           #+#    #+#             */
/*   Updated: 2022/07/10 15:27:46 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_builtin(t_cmd_struct *cmd_struct)
{ 	// check all error behaviours (e.g. too many arguments)
	if (!ft_strncmp(cmd_struct->command_splitted[0], "echo", ft_strlen(cmd_struct->command_splitted[0])))
	{
		//run echo
		return (1);
	}
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "cd", ft_strlen(cmd_struct->command_splitted[0])))
	{
		//run cd
		if (cmd_struct->command_splitted[2])
			ms_error(ft_strjoin("cd: string not in pwd: ", cmd_struct->command_splitted[1]), cmd_struct);
		builtin_cd(cmd_struct);
		return (1);
	}
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "pwd", ft_strlen(cmd_struct->command_splitted[0])))
	{
		if (cmd_struct->command_splitted[1])
			ms_error("pwd: too many arguments", cmd_struct);
		//run pwd
		builtin_pwd();
		return (1);
	}
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "export", ft_strlen(cmd_struct->command_splitted[0])))
	{
		//run export
		builtin_export(cmd_struct); //this should ignore additional arguments!
		return (1);
	}
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "unset", ft_strlen(cmd_struct->command_splitted[0])))
	{
		//run unset
		return (1);
	}
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "env", ft_strlen(cmd_struct->command_splitted[0])))
	{
		//run env
		return (1);
	}
	else if (!ft_strncmp(cmd_struct->command_splitted[0], "exit", ft_strlen(cmd_struct->command_splitted[0])))
	{
		//run exit
		return (1);
	}
	else
		return (0);
}