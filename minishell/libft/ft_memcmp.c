/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:33:35 by raweber           #+#    #+#             */
/*   Updated: 2022/05/03 11:00:26 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*casted_s1;
	unsigned char	*casted_s2;
	size_t			i;

	casted_s1 = (unsigned char *)s1;
	casted_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (casted_s1[i] != casted_s2[i])
			return ((unsigned char)casted_s1[i] - (unsigned char)casted_s2[i]);
		i++;
	}
	return (0);
}

// check if I use NULL?? check with original