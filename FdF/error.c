/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:16:54 by raweber           #+#    #+#             */
/*   Updated: 2022/05/29 19:51:13 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Displays an error and exits the program
int	ft_error(char *message, t_fdf *data)
{
	ft_printf("\n%s\n\n", message);
	destroy(data);
	exit(1);
}
