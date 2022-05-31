/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:18:46 by raweber           #+#    #+#             */
/*   Updated: 2022/05/29 16:47:54 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Destroys the image, window and frees all allocated memory
int	destroy(t_fdf *data)
{
	if (data->mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->z_matrix)
		free_maps(data->z_matrix, data);
	if (data->color_matrix)
		free_maps(data->color_matrix, data);
	free(data);
	exit(0);
}

// Frees all allocated memory of the z- and color-matrix
void	free_maps(int **matrix, t_fdf *data)
{
	int		i;

	i = data->height - 1;
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
}
