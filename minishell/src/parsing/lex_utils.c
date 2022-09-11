/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:34:23 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/03 19:41:10 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	lex_error(char *token)
{
	ft_printf("Minishell: syntax error%s\n", token);
	return (-1);
}

int	skip_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (i);
}

int	skip_quotes(char *s, char q)
{
	int	i;

	i = 1;
	while (s[i] != q)
		i++;
	return (i + 1);
}
