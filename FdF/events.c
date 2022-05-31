/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:05:32 by raweber           #+#    #+#             */
/*   Updated: 2022/05/29 19:34:58 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// The deal_key function handles the user input of different keys.
// If ESC is pressed, the whole program stops.
int	deal_key(int key, t_fdf *data)
{
	if (key == 126 || key == 125 || key == 124 || key == 123)
		deal_key_arrows(key, data);
	else if (key == 53)
		destroy(data);
	else if (key == 4 || key == 37 || key == 44 || key == 30)
		deal_key_scaling(key, data);
	else if (key == 18 || key == 19 || key == 256)
		deal_key_others(key, data);
	return (0);
}

/*
up-arrow: move figure down
down-arrow: move figure up
left-arrow: move figure right
right-arrow: move figure left
*/
void	deal_key_arrows(int key, t_fdf *data)
{
	if (key == 125)
	{	
		data->y_offset -= 10;
		draw(data);
	}
	if (key == 126)
	{	
		data->y_offset += 10;
		draw(data);
	}
	if (key == 123)
	{
		data->x_offset += 10;
		draw(data);
	}
	if (key == 124)
	{
		data->x_offset -= 10;
		draw(data);
	}
}

/*
'h': higher height scaling
'l': lower height scaling
'+': zoom in closer
'-': zoom away further
*/
void	deal_key_scaling(int key, t_fdf *data)
{
	if (key == 4)
	{
		data->height_zoom += 0.5;
		draw(data);
	}
	if (key == 37)
	{	
		data->height_zoom -= 0.5;
		draw(data);
	}
	if (key == 44)
	{	
		if (data->zoom > 0.5)
			data->zoom -= 0.5;
		draw(data);
	}
	if (key == 30)
	{	
		data->zoom += 0.5;
		draw(data);
	}
}

/*
'1': change projection angle positive
'2': change projection angle negative
'ctrl': go back to initial position and size
*/
void	deal_key_others(int key, t_fdf *data)
{
	if (key == 19)
	{	
		data->angle += 0.05;
		draw(data);
	}
	if (key == 18)
	{	
		data->angle -= 0.05;
		draw(data);
	}
	if (key == 256)
	{	
		data->zoom = ((float)data->win_height / 4 / (float)data->height);
		data->x_offset = (data->win_width / 2) - \
							(data->width / 2 * (int)data->zoom);
		data->y_offset = (data->win_height / 2) - \
							(data->height / 2 * (int)data->zoom);
		data->height_zoom = 3;
		data->angle = 0.9;
		draw(data);
	}
}
