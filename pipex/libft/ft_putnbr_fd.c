/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:44:20 by raweber           #+#    #+#             */
/*   Updated: 2022/05/01 16:14:03 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	new;

	new = (long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		new = -new;
	}
	if (new / 10)
	{
		ft_putnbr_fd(new / 10, fd);
	}
	ft_putchar_fd(new % 10 + '0', fd);
}
