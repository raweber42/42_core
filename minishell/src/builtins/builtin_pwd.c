/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:13:57 by raweber           #+#    #+#             */
/*   Updated: 2022/08/02 10:38:56 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Prints the current working directory (or an error message)
void	builtin_pwd(void)
{
	char	path_ptr[PATH_SIZE];

	if (!getcwd(path_ptr, PATH_SIZE))
	{
		perror("Error in getcwd");
		return ;
	}
	ft_printf("%s\n", path_ptr);
}
