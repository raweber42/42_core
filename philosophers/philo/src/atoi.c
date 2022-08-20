/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:47:03 by raweber           #+#    #+#             */
/*   Updated: 2022/07/01 15:17:07 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

// helper to detect whitespace
static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\f'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

// atoi that detects invalid input (negative, non-numeric)
int	philo_atoi(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == 0)
		return (-2);
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
		return (-2);
	while (str[i] > 47 && str[i] < 58)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (!str[0] || str[i])
		return (-2);
	if (result > 2147483647)
		return (-2);
	return (result);
}
