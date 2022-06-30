/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:16:39 by raweber           #+#    #+#             */
/*   Updated: 2022/06/24 11:14:54 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\f'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

long	ps_atol(const char *str, t_ps_list **bottom_a)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == 0)
		ps_error(bottom_a);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result *= 10;
		result += str[i++] - 48;
	}
	if (!str[0] || str[i] || (result * sign) > 2147483647
		|| (result * sign) < -2147483648)
		ps_error(bottom_a);
	return (sign * result);
}
