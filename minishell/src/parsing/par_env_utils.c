/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:16:58 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/04 15:00:26 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief Take two strings and compare them. 
 * If, in the first str the occurence of char from second str
 * is found, return index of that occurence. Else, return 
 * the end of the string.
 * Useful for counting word length.
 * @param s string to search through
 * @param check string to compare from
 * @return int
*/

int	check_ending(char *s, char *check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (check[j] != '\0')
		{
			if (s[i] == check[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

char	*get_new_temp(char *temp, char *value, char *s)
{
	char	*new_temp;

	new_temp = strjoin_err(temp, value);
	free(temp);
	temp = malloc((ft_strlen(s) + ft_strlen(value) + 1) * sizeof(char));
	if (!temp)
		return (return_with_strerror_ptr(errno));
	free(value);
	ft_strcpy(temp, new_temp);
	free(new_temp);
	return (temp);
}

void	copy_rest(char *s, char *temp, int *i, int *t)
{
	if (s[*i] == '\'')
	{
		temp[*t] = s[*i];
		*t = *t + 1;
		*i = *i + 1;
		while (s[*i] != '\'')
		{
			temp[*t] = s[*i];
			*t = *t + 1;
			*i = *i + 1;
		}
	}
	temp[*t] = s[*i];
	*t = *t + 1;
	*i = *i + 1;
}

char	*get_name(char *s, int i)
{
	int		j;
	char	*name;

	j = 0;
	name = malloc((i + 2) * sizeof(char));
	if (!name)
	{
		set_exit_status(strerror(errno), errno);
		write(2, "\n", 1);
		return (NULL);
	}
	while (j < i - 1)
	{
		name[j] = s[j];
		j++;
	}
	name[j] = '=';
	name[j + 1] = '\0';
	return (name);
}

char	*exit_or_dollar(char c, int *i)
{
	char	*value;

	value = NULL;
	if (c == '?')
		value = ft_itoa(g_exit_status);
	else if (c == ' ' || c == '\0')
	{
		value = malloc(2 * sizeof(char));
		value[0] = '$';
		value[1] = '\0';
	}
	*i = *i + 1;
	return (value);
}
