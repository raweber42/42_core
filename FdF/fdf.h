/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:58:40 by raweber           #+#    #+#             */
/*   Updated: 2022/05/29 19:23:52 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_data {
	char	*argv;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mlx_img;
	int		win_width;
	int		win_height;
	float	zoom;
	float	height_zoom;
	int		default_color;
	float	angle;
	int		bits_per_pxl;
	int		line_len;
	int		endian;
	char	*mlx_img_addr;
	int		x_offset;
	int		y_offset;
	int		height;
	int		width;
	int		**z_matrix;
	int		**color_matrix;

	int		iso_x;
	int		iso_y;
	int		iso_x1;
	int		iso_y1;
}				t_fdf;

void	init_data(t_fdf *data);
void	read_file(char *file_name, t_fdf *data);
void	draw(t_fdf *data);
void	line_drawing(t_fdf *data, int color);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	free_maps(int **matrix, t_fdf *data);
int		deal_key(int key, t_fdf *data);
void	deal_key_arrows(int key, t_fdf *data);
void	deal_key_esc(int key, t_fdf *data);
void	deal_key_scaling(int key, t_fdf *data);
void	deal_key_others(int key, t_fdf *data);
int		destroy(t_fdf *data);
int		ft_error(char *message, t_fdf *data);
void	fill_color_matrix_default(t_fdf *data);
int		color_atoi(const char *str, int *color, t_fdf *data);
void	make_x_isometric(int x, int y, t_fdf *data);
void	make_y_isometric(int x, int y, t_fdf *data);
void	allocate_matrixes(t_fdf *data);

#endif