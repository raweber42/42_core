/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:47:35 by raweber           #+#    #+#             */
/*   Updated: 2022/05/27 09:37:20 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// returns the isometric projection of x
static int	x_isometric(float x, float y, t_fdf *data)
{
	int	x_iso;

	x_iso = (int)((x - y) * cos(data->angle));
	return (x_iso);
}

// returns the isometric projection of y
static int	y_isometric(float x, float y, int z, t_fdf *data)
{
	int	y_iso;

	y_iso = (int)((x + y) * sin(data->angle) - z);
	return (y_iso);
}

/*
>>CASE X INCREMENTED<<
Takes all x,y and z variables, applies the zoom values,
calls isometric subfunctions to transform them into 
isometric projections and passes them to the line drawing function
*/
void	make_x_isometric(int x, int y, t_fdf *data)
{
	int		x1;
	int		y1;
	int		z;
	int		z1;
	int		color;

	x1 = x + 1;
	y1 = y;
	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	color = data->color_matrix[(int)y][(int)x];
	x = (int)(x * data->zoom);
	y = (int)(y * data->zoom);
	x1 = (int)(x1 * data->zoom);
	y1 = (int)(y1 * data->zoom);
	z = (int)(z * data->height_zoom);
	z1 = (int)(z1 * data->height_zoom);
	data->iso_x = x_isometric(x, y, data);
	data->iso_y = y_isometric(data->iso_x, y, z, data);
	data->iso_x1 = x_isometric(x1, y1, data);
	data->iso_y1 = y_isometric(data->iso_x1, y1, z1, data);
	line_drawing(data, color);
}

/* 
>>CASE Y INCREMENTED<<
Takes all x,y and z variables, applies the zoom values,
calls isometric subfunctions to transform them into 
isometric projections and passes them to the line drawing function
*/
void	make_y_isometric(int x, int y, t_fdf *data)
{
	int		x1;
	int		y1;
	int		z;
	int		z1;
	int		color;

	x1 = x;
	y1 = y + 1;
	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	color = data->color_matrix[(int)y][(int)x];
	x = (int)(x * data->zoom);
	y = (int)(y * data->zoom);
	x1 = (int)(x1 * data->zoom);
	y1 = (int)(y1 * data->zoom);
	z = (int)(z * data->height_zoom);
	z1 = (int)(z1 * data->height_zoom);
	data->iso_x = x_isometric(x, y, data);
	data->iso_y = y_isometric(data->iso_x, y, z, data);
	data->iso_x1 = x_isometric(x1, y1, data);
	data->iso_y1 = y_isometric(data->iso_x1, y1, z1, data);
	line_drawing(data, color);
}
