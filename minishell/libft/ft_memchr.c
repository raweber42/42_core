/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:07:13 by raweber           #+#    #+#             */
/*   Updated: 2022/05/12 17:25:50 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	converted_c;
	unsigned char	*casted_s;
	size_t			i;

	converted_c = c;
	casted_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (casted_s[i] == converted_c)
		{
			return (&casted_s[i]);
		}
		i++;
	}
	return (0);
}
