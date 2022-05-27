/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:09:56 by raweber           #+#    #+#             */
/*   Updated: 2022/05/27 20:30:26 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	allocate_matrixes(t_fdf *data)
{
	int	i;

	data->z_matrix = (int **)ft_calloc((data->height), sizeof(int *));
	if (!data->z_matrix)
		ft_error("Could not allocate memory for z_matrix.", data);
	data->color_matrix = (int **)ft_calloc((data->height), sizeof(int *));
	if (!data->color_matrix)
		ft_error("Could not allocate memory for color_matrix.", data);
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)ft_calloc((data->width), sizeof(int));
		if (!data->z_matrix)
			ft_error("Could not allocate memory for z_matrix.", data);
		data->color_matrix[i] = (int *)ft_calloc(data->width, sizeof(int));
		if (!data->color_matrix)
			ft_error("Could not allocate memory for color_matrix.", data);
		i++;
	}
}
