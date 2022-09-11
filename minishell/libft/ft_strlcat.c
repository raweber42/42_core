/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:04:57 by raweber           #+#    #+#             */
/*   Updated: 2022/05/01 16:13:29 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	j;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	j = 0;
	if (dstsize == 0 || dstsize <= len_dest)
	{
		return (dstsize + len_src);
	}
	while ((j < (dstsize - len_dest - 1)) && (src[j] != 0))
	{
		dst[len_dest + j] = src[j];
		j++;
	}
	dst[len_dest + j] = '\0';
	return (len_dest + len_src);
}
