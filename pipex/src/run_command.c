/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:12:38 by raweber           #+#    #+#             */
/*   Updated: 2022/06/23 14:04:51 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// runs command, prints error, if not executed
void	run_execve(t_pipex_list *command_ll, char **envp)
{
	execve(command_ll->command_path, command_ll->command_splitted, envp);
	pipex_error("Error: One of the commands is invalid", command_ll);
}
