/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:01:46 by raweber           #+#    #+#             */
/*   Updated: 2022/05/20 11:19:58 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str_counter(char const *str, char del)
{
	size_t	counter;

	if (!*str)
		return (0);
	counter = 0;
	while (*str)
	{
		if (*str != del && ((*(str + 1)) == del || (*(str + 1)) == 0))
			counter++;
		str++;
	}
	return (counter);
}

static size_t	ft_wordlen_helper(const char *s, char c)
{
	size_t	word_len;

	if (!ft_strchr(s, c))
		word_len = ft_strlen(s);
	else
		word_len = ft_strchr(s, c) - s;
	return (word_len);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	word_len;

	if (!s)
		return (0);
	arr = malloc((ft_str_counter(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_len = ft_wordlen_helper(s, c);
			arr[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	arr[i] = NULL;
	return (arr);
}
