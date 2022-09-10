/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:03:54 by raweber           #+#    #+#             */
/*   Updated: 2022/05/01 16:14:44 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	char			*casted_s;
	size_t			i;

	casted_s = (char *)s;
	i = 0;
	while (i < len)
	{
		casted_s[i] = 0;
		i++;
	}
}
