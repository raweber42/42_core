/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_token_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:19:22 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/04 08:13:21 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*init_quotes(char *s, int *i, char q)
{
	t_token	*token;
	int		len;

	len = skip_quotes(s, q);
	token = malloc(sizeof(t_token));
	if (!token)
	{
		set_exit_status(strerror(errno), errno);
		write(2, "\n", 1);
		return (NULL);
	}
	token->string = ft_substr(s, 1, (size_t)len - 2);
	token->type = WORD;
	token->next = NULL;
	*i += len;
	return (token);
}

t_token	*init_pipe_or_sep(char *s, int *i, char p_or_s)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (return_with_strerror_tkn(errno));
	token->string = malloc(sizeof(char));
	if (!token->string)
		return (return_with_strerror_tkn(errno));
	token->string[0] = '\0';
	token->next = NULL;
	if (p_or_s == ' ')
	{
		*i += skip_spaces(s);
		token->type = SEP;
	}
	else
	{
		*i = *i + 1;
		token->type = PIPE;
	}
	return (token);
}

t_token	*init_single_red(char *s, int *i, char in_or_out)
{
	t_token	*token;
	int		len;

	*i += skip_spaces(&s[*i + 1]) + 1;
	len = check_ending(&s[*i], " <>|");
	token = malloc(sizeof(t_token));
	if (!token)
	{
		set_exit_status(strerror(errno), errno);
		write(2, "\n", 1);
		return (NULL);
	}
	token->string = ft_substr(s, *i, len);
	throw_away_quotes(token->string);
	token->next = NULL;
	if (in_or_out == '<')
		token->type = IN_RED;
	else if (in_or_out == '>')
		token->type = OUT_RED;
	*i += len;
	return (token);
}

t_token	*init_double_red(char *s, int *i, char in_or_out)
{
	t_token	*token;
	int		len;

	*i += skip_spaces(&s[*i + 2]) + 2;
	len = check_ending(&s[*i], " <>|");
	token = malloc(sizeof(t_token));
	if (!token)
	{
		set_exit_status(strerror(errno), errno);
		write(2, "\n", 1);
		return (NULL);
	}
	token->string = ft_substr(s, *i, len);
	throw_away_quotes(token->string);
	token->next = NULL;
	if (in_or_out == '<')
		token->type = HERE_DOC;
	else if (in_or_out == '>')
		token->type = APPEND_RED;
	*i += len;
	return (token);
}

t_token	*init_word(char *s, int *i)
{
	t_token	*token;
	int		len;

	len = check_ending(&s[*i], " '\"<>|");
	token = malloc(sizeof(t_token));
	if (!token)
	{
		set_exit_status(strerror(errno), errno);
		write(2, "\n", 1);
		return (NULL);
	}
	token->string = ft_substr(s, *i, len);
	token->type = WORD;
	token->next = NULL;
	*i += len;
	return (token);
}
