/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:54:36 by raweber           #+#    #+#             */
/*   Updated: 2022/05/27 21:11:15 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdlib.h>



// Inititalizes a lot of the fdf struct data.
// Sets default values and starts the mlx engine.
void	init_data(t_fdf *data)
{
	data->mlx_ptr = NULL;
	data->mlx_img = NULL;
	data->win_ptr = NULL;
	data->mlx_img_addr = NULL;
	data->win_width = 1000;
	data->win_height = 1000;
	data->zoom = 0.1;
	data->height_zoom = 1;
	data->default_color = 0xFFFFFF;
	data->angle = 0.9;
	data->bits_per_pxl = 0;
	data->line_len = 0;
	data->endian = 0;
	data->z_matrix = NULL;
	data->color_matrix = NULL;
}

void	init_mlx(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
					data->win_width, data->win_height, "FdF");
	data->mlx_img = mlx_new_image(data->mlx_ptr, \
					data->win_width, data->win_height);
	data->mlx_img_addr = mlx_get_data_addr(data->mlx_img, \
					&data->bits_per_pxl, &data->line_len, &data->endian);
}

/*
Initializes the program and calls all subfunctions to initialize the struct and 
to allocate and fill the needed datatypes. Also gives functionality to keys 
(autorepeat only for mac, use mlx_keyhook on linux!). 
Program runs as long as it is not told to stop 
(To stop: ESC or Mouseclick on Window Manager)
*/
int	main(int argc, char **argv)
{
	t_fdf	*data;

	data = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	if (!data)
		return (0);
	if (argc != 2)
		ft_error("Wrong input! Try: ./fdf <your_map_name>.fdf", data);
	data->argv = argv[1];
	init_data(data);
	read_file(argv[1], data);
	init_mlx(data);
	data->zoom = ((float)data->win_height / 4 / (float)data->height);
	if (data->zoom <= 0)
		ft_error("Error while calculating zoom!", data);
	data->x_offset = data->win_width / 2 - data->width / 2 * (int)data->zoom;
	data->y_offset = data->win_height / 2 - data->height / 2 * (int)data->zoom;
	if (data->x_offset < 0 || data->y_offset < 0)
		ft_error("Error while calculating offset!", data);
	draw(data);
	mlx_hook(data->win_ptr, 2, 0, &deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, &destroy, data);
	mlx_loop(data->mlx_ptr);
}
