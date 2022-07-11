/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:16:21 by raweber           #+#    #+#             */
/*   Updated: 2022/07/05 11:18:28 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_error(char *message, t_cmd_struct *cmd_struct)
{
	ft_printf("%s\n", message);
	// free stuff
	if (cmd_struct) //--> remove this!
		exit(1); //--> remove this!
	exit(1); //-->remove this!
}