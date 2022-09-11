/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:16:21 by raweber           #+#    #+#             */
/*   Updated: 2022/08/03 08:33:37 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// how to exit and stop everything else?
void	set_exit_status(char *string, int exit_int)
{
	ft_putstr_fd(string, 2);
	g_exit_status = exit_int;
}

// prints an error, if fork failed
int	fork_failed(int pid)
{
	if (pid == -1)
	{
		set_exit_status("Error: Could not fork the process\n", 1);
		return (1);
	}
	return (0);
}
