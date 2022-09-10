/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:08:48 by ialinaok          #+#    #+#             */
/*   Updated: 2022/08/04 08:05:31 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*last_token(t_token *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	token_add_back(t_token **list, t_token *new)
{
	t_token	*last;

	if (*list != NULL)
	{
		last = last_token(*list);
		last->next = new;
	}
	else
		*list = new;
}

void	throw_away_quotes(char *s)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == '\'')
		{
			len -= 2;
			quotes_gone(s, s[i], &i, &j);
		}
		else if (s[i] == '"')
		{
			len -= 2;
			quotes_gone(s, s[i], &i, &j);
		}
		s[j] = s[i];
		j++;
		i++;
	}
	s[j] = '\0';
}

void	quotes_gone(char *s, char q, int *i, int *j)
{
	*i = *i + 1;
	while (s[*i] != q)
	{
		s[*j] = s[*i];
		*i = *i + 1;
		*j = *j + 1;
	}
	*i = *i + 2;
	*j = *j + 1;
}

void	tokenizer(char *s, t_token **token_list)
{
	t_token	*token;
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'' || s[i] == '"')
			token = init_quotes(&s[i], &i, s[i]);
		else if (s[i] == '|' || s[i] == ' ')
			token = init_pipe_or_sep(&s[i], &i, s[i]);
		else if ((s[i] == '>' && s[i + 1] != '>') || \
				(s[i] == '<' && s[i + 1] != '<'))
			token = init_single_red(s, &i, s[i]);
		else if ((s[i] == '<' && s[i + 1] == '<') || \
				(s[i] == '>' && s[i + 1] == '>'))
			token = init_double_red(s, &i, s[i]);
		else
			token = init_word(s, &i);
		token_add_back(token_list, token);
	}
}
