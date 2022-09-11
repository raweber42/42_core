/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:20:49 by raweber           #+#    #+#             */
/*   Updated: 2022/08/03 16:56:23 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Prints a prompt message. Also reads and returns user input as a string.
char	*prompt(void)
{
	char	*input;
	char	*prompt;

	prompt = "[BtB]$ ";
	input = readline(prompt);
	if (ft_strlen(input) > 0)
		add_history(input);
	return (input);
}
