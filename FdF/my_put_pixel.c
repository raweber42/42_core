/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:46:25 by raweber           #+#    #+#             */
/*   Updated: 2022/05/29 19:22:39 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x < data->win_width && y < data->win_height && x > 0 && y > 0)
	{
		dst = data->mlx_img_addr + (y * data->line_len \
								+ x * (data->bits_per_pxl / 8));
		*(unsigned int *) dst = color;
	}
}
