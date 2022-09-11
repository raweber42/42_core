/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:47:41 by raweber           #+#    #+#             */
/*   Updated: 2022/05/01 16:15:37 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	converted_c;
	char			*casted_b;
	size_t			i;

	converted_c = c;
	casted_b = (char *)b;
	i = 0;
	while (i < len)
	{
		casted_b[i] = converted_c;
		i++;
	}
	return (casted_b);
}
