/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:17:01 by raweber           #+#    #+#             */
/*   Updated: 2022/05/19 19:58:20 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		strlen;

	strlen = ft_strlen(s1);
	dest = malloc(strlen + 1);
	if (dest == 0)
		return (0);
	ft_strcpy(dest, (char *)s1);
	return (dest);
}
