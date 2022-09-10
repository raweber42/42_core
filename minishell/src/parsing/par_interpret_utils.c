/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_interpret_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:15:21 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/04 14:05:39 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmd_struct	*create_new(t_cmd_struct *cmd, int *c)
{
	char			**env;
	t_cmd_struct	**temp_start;

	temp_start = cmd->list_start;
	env = cmd->env_clone;
	cmd->next = malloc(sizeof(t_cmd_struct));
	if (!cmd->next)
	{
		set_exit_status(strerror(errno), errno);
		write(2, "\n", 1);
		return (NULL);
	}
	cmd = cmd->next;
	cmd->cur_env_size = get_array_size(env) * 2;
	cmd->env_clone = copy_env(env, cmd);
	cmd->list_start = temp_start;
	cmd->next = NULL;
	*c = *c + 1;
	return (cmd);
}

int	count_args(t_token **token_list)
{
	t_token	*temp;
	int		count;

	temp = *token_list;
	count = 0;
	while (temp != NULL && temp->type != PIPE)
	{
		if (temp->type == WORD)
			count++;
		temp = temp->next;
	}
	return (count);
}

void	init_cmd_node(t_cmd_struct *cmd, t_token **tkn, int cmd_count)
{
	int		args;
	int		n;

	args = count_args(tkn);
	n = 0;
	cmd->command_splitted = malloc((args + 1) * sizeof(char *));
	if (!cmd->command_splitted)
		return (return_void(errno));
	cmd->fd_infile = 0;
	cmd->fd_outfile = 1;
	cmd->command_nbr = cmd_count;
	while (n <= args)
	{
		cmd->command_splitted[n] = NULL;
		n++;
	}
}
