/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:56:27 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/03 19:40:25 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_lex_errors(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '&' && s[i + 1] == '&')
			return (lex_error(" near unexpected token: `&'"));
		if (s[i] == '&' && s[i + 1] == '&' && s[i + 2] == '&')
			return (lex_error(" near unexpected token: `&&'"));
		else if (s[i] == '|' && s[i + 1] == '|')
			return (lex_error(" near unexpected token: `|'"));
		else if (s[i] == '|' && s[i + 1] == '|' && s[i + 2] == '|')
			return (lex_error(" near unexpected token: `||'"));
		else if (s[i] == '<' && s[i + 1] == '<' && s[i + 2] == '<')
			return (lex_error(" near unexpected token: `<'"));
		else if (s[i] == '>' && s[i + 1] == '>' && s[i + 2] == '>')
			return (lex_error(" near unexpected token: `>'"));
		else
			i++;
	}
	return (0);
}

int	check_only_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '\0')
		return (-1);
	else
		return (0);
}

int	check_unclosed_quotes(char *s)
{
	bool	dq_open;
	bool	sq_open;
	int		i;

	i = 0;
	dq_open = false;
	sq_open = false;
	while (s[i] != '\0')
	{
		if (s[i] == '\'' && !dq_open && !sq_open)
			sq_open = true;
		else if (s[i] == '\'' && !dq_open && sq_open)
			sq_open = false;
		else if (s[i] == '"' && !dq_open && !sq_open)
			dq_open = true;
		else if (s[i] == '"' && dq_open && !sq_open)
			dq_open = false;
		i++;
	}
	if (dq_open)
		return (lex_error(": unclosed double quotes"));
	if (sq_open)
		return (lex_error(": unclosed single quotes"));
	return (0);
}

int	check_pipes(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '|')
		return (lex_error(" near unexpected token: `|'"));
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
			i += skip_quotes(&s[i], '\'');
		else if (s[i] == '"')
			i += skip_quotes(&s[i], '"');
		else if (s[i] == '|')
		{
			i++;
			while (s[i] == ' ')
				i++;
			if (s[i] == '|' || s[i] == '\0')
				return (lex_error(" near unexpected token: `|'"));
		}
		else
			i++;
	}
	return (0);
}
