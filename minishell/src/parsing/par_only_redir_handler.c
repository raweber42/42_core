/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_only_redir_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:35:09 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/03 19:47:48 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	redirector(t_token **token_list)
{
	t_token	*tkn;
	int		infile;
	int		outfile;
	int		ret;

	tkn = *token_list;
	infile = 0;
	outfile = 1;
	while (tkn != NULL)
	{
		if (tkn->type == IN_RED)
			ret = handle_in_redir(&infile, tkn->string);
		else if (tkn->type == OUT_RED)
			ret = handle_out_redir(&outfile, tkn->string);
		else if (tkn->type == APPEND_RED)
			ret = handle_append(&outfile, tkn->string);
		else if (tkn->type == HERE_DOC)
			ret = handle_heredoc(&infile, tkn->string);
		if (ret == -1)
			break ;
		tkn = tkn->next;
	}
	just_close(&infile, &outfile);
	return (0);
}

int	checker(t_token **token_list)
{
	t_token	*tkn;

	tkn = *token_list;
	while (tkn != NULL)
	{
		if (tkn->type == WORD)
			return (-1);
		tkn = tkn->next;
	}
	return (0);
}

void	just_close(int *infile, int *outfile)
{
	if (*infile != 0)
		close(*infile);
	if (*outfile != 1)
		close(*outfile);
}
