/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:44:38 by apielasz          #+#    #+#             */
/*   Updated: 2022/08/04 08:13:38 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	free_in_handler(char *input)
{
	free(input);
	return (-1);
}

int	return_with_strerror(int err)
{
	set_exit_status(strerror(err), err);
	write(2, "\n", 1);
	return (-1);
}

char	*return_with_strerror_ptr(int err)
{
	set_exit_status(strerror(err), err);
	write(2, "\n", 1);
	return (NULL);
}

void	return_void(int err)
{
	set_exit_status(strerror(err), err);
	write(2, "\n", 1);
	return ;
}

t_token	*return_with_strerror_tkn(int err)
{
	set_exit_status(strerror(err), err);
	write(2, "\n", 1);
	return (NULL);
}
