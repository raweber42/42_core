/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 09:24:28 by raweber           #+#    #+#             */
/*   Updated: 2022/07/29 20:58:56 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_itoa_recursive(long n, char *str)
{
	char	c;

	if (n < 0)
	{
		*str++ = '-';
		ft_itoa_recursive(-n, str);
		return ;
	}
	if (n == 0)
	{
		*str++ = '0';
		*str = '\0';
		return ;
	}
	c = n % 10 + '0';
	ft_itoa_recursive(n / 10, str);
	while (n / 10)
	{	
		str++;
		n /= 10;
	}
	*str++ = c;
	*str = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_intlen(n);
	str = malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	ft_itoa_recursive((long)n, str);
	return (str);
}
