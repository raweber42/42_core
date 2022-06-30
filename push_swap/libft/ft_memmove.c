/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:24:58 by raweber           #+#    #+#             */
/*   Updated: 2022/05/02 12:50:16 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if src < dst copy from back to front, otherwise use ft_memcpy
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*casted_dst;
	char			*casted_src;

	casted_dst = (char *)dst;
	casted_src = (char *)src;
	if (n == 0 || (!casted_dst && !casted_src))
		return (dst);
	if (src < dst)
	{
		while (n--)
		{
			casted_dst[n] = casted_src[n];
		}
		return (dst);
	}
	ft_memcpy(dst, src, n);
	return (dst);
}
