/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:00:44 by raweber           #+#    #+#             */
/*   Updated: 2022/08/03 08:36:27 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_strjoin_zero_allowed(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
	{
		set_exit_status("Error: malloc failed strjoin_zero_allowed\n", 1);
		return (NULL);
	}
	while (s1[i] != 0)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != 0)
	{
		new_str[i++] = s2[j++];
	}
	new_str[i] = 0;
	return (new_str);
}

char	*strjoin_err(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
	{
		set_exit_status("Error: malloc failed strjoin_err\n", 1);
		return (NULL);
	}
	while (s1[i] != 0)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
		new_str[i++] = s2[j++];
	new_str[i] = 0;
	return (new_str);
}

char	*strjoin_no_free(char *result, char *temp)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_string = malloc(ft_strlen(result) + ft_strlen(temp) + 1);
	if (new_string == 0)
	{
		set_exit_status("Error: malloc failed strjoin_no_free\n", 1);
		return (NULL);
	}
	if (result)
	{
		while (result[i])
		{	
			new_string[i] = result[i];
			i++;
		}
	}
	while (temp[j])
		new_string[i++] = temp[j++];
	new_string[i] = '\0';
	return (new_string);
}

// Joins two strings and free()'s the second one
char	*strjoin_free_second(char *str1, char *str2)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_string = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!new_string)
	{
		set_exit_status("Error: malloc failed in strjoin_free_second\n", 1);
		return (NULL);
	}
	while (str1 && str1[i])
	{
		new_string[i] = str1[i];
		i++;
	}
	if (str2)
	{
		while (str2[j])
			new_string[i++] = str2[j++];
		free(str2);
	}
	new_string[i] = '\0';
	return (new_string);
}

// Joins two strings and free()'s both afterwards
char	*strjoin_free_both(char *str1, char *str2)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_string = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (new_string == 0)
	{
		set_exit_status("Error: malloc failed in strjoin_free_both\n", 1);
		return (NULL);
	}
	while (str1[i])
	{
		new_string[i] = str1[i];
		i++;
	}
	free(str1);
	while (str2 && str2[j])
		new_string[i++] = str2[j++];
	free(str2);
	new_string[i] = '\0';
	return (new_string);
}
