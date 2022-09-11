/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_interpret_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:38:23 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/04 15:00:43 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	interpreter(t_token **token_list, t_cmd_struct *cmd)
{
	t_token			*tkn;
	int				n;
	int				cmd_count;

	tkn = *token_list;
	n = 0;
	cmd_count = 0;
	while (tkn != NULL)
	{
		n = 0;
		init_cmd_node(cmd, &tkn, cmd_count);
		tkn = interpret_loop(&tkn, cmd, &n);
		if (tkn != NULL && tkn->type == PIPE)
		{
			cmd->next = create_new(cmd, &cmd_count);
			cmd = cmd->next;
			tkn = tkn->next;
		}
	}
	return (0);
}

t_token	*handle_sep(t_token **tkn_list, t_cmd_struct *cmd, int *n)
{
	t_token	*tkn;
	char	*temp;

	tkn = *tkn_list;
	tkn = tkn->next;
	if (tkn && tkn->type == WORD)
	{
		if (*n == 0 && cmd->command_splitted[*n] == NULL)
			;
		else
			*n = *n + 1;
		temp = strjoin_no_free(cmd->command_splitted[*n], tkn->string);
		cmd->command_splitted[*n] = temp;
		if (*n == 0)
		{
			set_command_path(cmd->env_clone, cmd);
			if (!cmd->command_path)
				return (NULL);
		}
		tkn = tkn->next;
	}
	return (tkn);
}

t_token	*handle_word(t_token **tkn_list, t_cmd_struct *cmd, int *n)
{
	char	*temp;
	t_token	*tkn;

	tkn = *tkn_list;
	temp = strjoin_no_free(cmd->command_splitted[*n], tkn->string);
	free(cmd->command_splitted[*n]);
	cmd->command_splitted[*n] = temp;
	if (*n == 0)
	{
		set_command_path(cmd->env_clone, cmd);
		if (!cmd->command_path)
			return (NULL);
	}
	return (tkn->next);
}

t_token	*handle_redirs(t_token **tkn_list, t_cmd_struct *cmd)
{
	t_token	*tkn;

	tkn = *tkn_list;
	if (tkn && tkn->type == IN_RED)
		handle_in_redir(&cmd->fd_infile, tkn->string);
	else if (tkn && tkn->type == OUT_RED)
		handle_out_redir(&cmd->fd_outfile, tkn->string);
	else if (tkn && tkn->type == APPEND_RED)
		handle_append(&cmd->fd_outfile, tkn->string);
	else if (tkn && tkn->type == HERE_DOC)
		handle_heredoc(&cmd->fd_infile, tkn->string);
	return (tkn->next);
}

t_token	*interpret_loop(t_token **tknl, t_cmd_struct *cmd, int *n)
{
	t_token	*tkn;

	tkn = *tknl;
	while (tkn != NULL && tkn->type != PIPE)
	{
		if (tkn && (tkn->type == IN_RED || tkn->type == OUT_RED \
			|| tkn->type == APPEND_RED || tkn->type == HERE_DOC))
			tkn = handle_redirs(&tkn, cmd);
		else if (tkn && tkn->type == SEP)
			tkn = handle_sep(&tkn, cmd, n);
		else if (tkn && tkn->type == WORD)
			tkn = handle_word(&tkn, cmd, n);
	}
	return (tkn);
}
