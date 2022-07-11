/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:20:49 by raweber           #+#    #+#             */
/*   Updated: 2022/07/05 12:57:14 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*prompt(void)
{
	char	*input;
	char	*prompt;

	prompt = "BtB$ ";
	// betterthanbash :)
	input = readline(prompt);
	if (!input)
		return (NULL);
	// additional error handling? empty input, trim away spaces at beginning and end?

	return (input);
}