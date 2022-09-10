/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_env_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:28:51 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/04 14:45:37 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief Copy a value of env_var into allocated string.
 * @param env_var
 * @return char*
 */

char	*copy_var_value(char *env_var)
{
	int		i;
	char	*value;

	i = 0;
	value = malloc((ft_strlen(env_var) + 1) * sizeof(char));
	if (!value)
		return (return_with_strerror_ptr(errno));
	while (env_var[i] != '\0')
	{
		value[i] = env_var[i];
		i++;
	}
	value[i] = '\0';
	return (value);
}

/**
 * @brief Get the variable value. Search environment,
 * find the variable, and copy it's value.
 * @param env environment variable char *[]
 * @param name name of the environment variable
 * @return char* 
 */

char	*get_variable_value(char **env, char *name)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	j = 0;
	value = NULL;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
		{
			while (env[i][j] != '=')
				j++;
			j++;
			value = copy_var_value(&env[i][j]);
			break ;
		}
		i++;
	}
	if (env[i] == NULL && value == NULL)
		value = variable_not_found();
	return (value);
}

char	*variable_not_found(void)
{
	char	*value;

	value = malloc(1);
	if (!value)
		return (return_with_strerror_ptr(errno));
	value[0] = '\0';
	return (value);
}

/**
 * @brief Find a given environment variable and gets it's value.
 * returns the end of the variable name.
 * @param envp environment variable char *[]
 * @param s string with $ as a first char
 * @param value the value of expanded variable
 * @return int 
 */

int	find_variable(char **envp, char *s, char **value)
{
	int		i;
	char	*name;

	i = 1;
	name = NULL;
	if (s[i] == '?' || s[i] == ' ' || s[i] == '\0')
		*value = exit_or_dollar(s[i], &i);
	else
	{
		i += check_ending(&s[i], " <>|\"'$[]{}()");
		name = get_name(&s[1], i);
		if (!name)
			return (i);
		*value = get_variable_value(envp, name);
		free(name);
	}
	return (i);
}

char	*expander(char **envp, char *s)
{
	char	*temp;
	char	*value;
	int		i;
	int		t;

	i = 0;
	t = 0;
	value = NULL;
	temp = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!temp)
		return (return_with_strerror_ptr(errno));
	while (s[i] != '\0')
	{
		if (s[i] == '$')
		{
			temp[t] = '\0';
			i += find_variable(envp, &s[i], &value);
			t += ft_strlen(value);
			temp = get_new_temp(temp, value, s);
		}
		else
			copy_rest(s, temp, &i, &t);
	}
	temp[t] = '\0';
	return (temp);
}
