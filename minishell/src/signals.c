/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:59:59 by raweber           #+#    #+#             */
/*   Updated: 2022/08/02 18:46:18 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	signal_interactive(void)
{
	signal(SIGINT, &interactive_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_not_interactive(void)
{
	signal(SIGINT, &non_interactive_handler);
	signal(SIGQUIT, &non_interactive_handler);
}

void	interactive_sigint(int sign)
{
	if (sign == SIGINT)
	{
		g_exit_status = 128 + sign;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	non_interactive_handler(int sign)
{
	if (sign == SIGINT)
	{
		g_exit_status = 128 + sign;
		write(1, "\n", 1);
		rl_replace_line("", 0);
	}
	else if (sign == SIGQUIT)
	{
		g_exit_status = 128 + sign;
		ft_putstr_fd("Quit\n", 1);
	}
}

void	signal_child_active(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
