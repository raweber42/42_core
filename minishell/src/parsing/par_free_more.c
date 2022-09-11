/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_free_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:30:01 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/03 19:42:59 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_token_list(t_token **token_list)
{
	t_token	*temp;

	temp = *token_list;
	while (*token_list != NULL)
	{
		if (temp->string)
			free(temp->string);
		temp = temp->next;
		free(*token_list);
		*token_list = temp;
	}
}

int	free_with_token_free(t_token **token_list)
{
	free_token_list(token_list);
	return (-1);
}

int	free_token_and_struct(t_token **list, t_cmd_struct *cmd)
{
	free_token_list(list);
	loop_clean_up(cmd);
	return (-1);
}
