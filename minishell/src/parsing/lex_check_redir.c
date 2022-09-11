/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_check_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:23:24 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/05 09:25:47 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_redirections(char *s)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0' && ret != -1)
	{
		if (s[i] == '\'')
			i += skip_quotes(&s[i], '\'');
		else if (s[i] == '"')
			i += skip_quotes(&s[i], '"');
		else if (s[i] == '<' && s[i + 1] != '<')
			ret = check_single_inredir(s, &i);
		else if (s[i] == '<' && s[i + 1] == '<')
			ret = check_double_inredir(s, &i);
		else if (s[i] == '>' && s[i + 1] != '>')
			ret = check_single_outredir(s, &i);
		else if (s[i] == '>' && s[i + 1] == '>')
			ret = check_double_outredir(s, &i);
		else
			i++;
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int	check_single_inredir(char *s, int *i)
{
	*i += skip_spaces(&s[*i + 1]) + 1;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
		return (lex_error(" near unexpected token: `<'"));
	return (*i);
}

int	check_single_outredir(char *s, int *i)
{
	*i += skip_spaces(&s[*i + 1]) + 1;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
		return (lex_error(" near unexpected token: `>'"));
	return (*i);
}

int	check_double_inredir(char *s, int *i)
{
	*i += skip_spaces(&s[*i + 2]) + 2;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
		return (lex_error(" near unexpected token: `<<'"));
	return (*i);
}

int	check_double_outredir(char *s, int *i)
{
	*i += skip_spaces(&s[*i + 2]) + 2;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
		return (lex_error(" near unexpected token: `>>'"));
	return (*i);
}
