/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:49:29 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/04 15:01:10 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	skip_from_end(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '|')
		i++;
	i--;
	while (s[i] == ' ')
		i--;
	return (i);
}

int	parser(t_cmd_struct *cmd_struct, char *s)
{
	char	*exp;
	t_token	*token_list;

	token_list = NULL;
	exp = expander(cmd_struct->env_clone, s);
	free(s);
	tokenizer(exp, &token_list);
	free(exp);
	if (checker(&token_list) == 0)
	{
		if (redirector(&token_list) == 0)
			return (free_with_token_free(&token_list));
	}
	if (interpreter(&token_list, cmd_struct) == -1)
		return (free_token_and_struct(&token_list, cmd_struct));
	free_token_list(&token_list);
	return (0);
}

int	handle_input(t_cmd_struct *cmd_struct, char *input)
{
	if (check_lex_errors(input) == -1)
		return (free_in_handler(input));
	else if (check_only_spaces(input) == -1)
		return (free_in_handler(input));
	else if (check_unclosed_quotes(input) == -1)
		return (free_in_handler(input));
	else if (check_redirections(input) == -1)
		return (free_in_handler(input));
	else if (check_pipes(input) == -1)
		return (free_in_handler(input));
	if (parser(cmd_struct, input) == -1)
		return (-1);
	return (0);
}
