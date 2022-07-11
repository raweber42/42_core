/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:13:57 by raweber           #+#    #+#             */
/*   Updated: 2022/07/06 12:20:27 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	builtin_pwd(void)
{
	char	*path_ptr;
	
	path_ptr = getcwd(NULL, 0);		
	ft_printf("from minishell: %s\n", path_ptr); // check again if newline needed! maybe also error handling?
	free(path_ptr);
}
