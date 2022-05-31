/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:30:26 by raweber           #+#    #+#             */
/*   Updated: 2022/05/29 19:34:47 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_drawing(t_fdf *data, int color)
{
	float	x_step;
	float	y_step;
	int		steps;
	float	x_float;
	float	y_float;

	x_float = (float) data->iso_x;
	y_float = (float) data->iso_y;
	x_step = data->iso_x1 - x_float;
	y_step = data->iso_y1 - y_float;
	if (fabsf(x_step) >= fabsf(y_step))
		steps = (int)fabsf(x_step);
	else
		steps = (int)fabsf(y_step);
	x_step /= (float)steps;
	y_step /= (float)steps;
	while ((int)(x_float - data->iso_x1) || (int)(y_float - data->iso_y1))
	{
		my_mlx_pixel_put(data, (data->x_offset + (int)x_float), \
						(data->y_offset + (int)y_float), color);
		x_float += x_step;
		y_float += y_step;
	}
}

/*
Sends out function calls for all points of the 
map that have been read by read_file.c and puts them
on an image. If an image already exists, it will
be destroyed before.
*/
void	draw(t_fdf *data)
{
	int	x;
	int	y;

	if (data->mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->mlx_img);
		data->mlx_img = mlx_new_image(data->mlx_ptr, \
				data->win_width, data->win_height);
	}
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				make_x_isometric(x, y, data);
			if (y < data->height - 1)
				make_y_isometric(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
}
