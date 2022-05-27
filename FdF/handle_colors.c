/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:04:33 by raweber           #+#    #+#             */
/*   Updated: 2022/05/27 09:37:34 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// fills the whole color matrix with the default color
void	fill_color_matrix_default(t_fdf *data)
{
	int	color;
	int	x;
	int	y;

	color = data->default_color;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->color_matrix[y][x] = color;
			x++;
		}
		y++;
	}
}

// helper function for skipping whitespace
static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\f'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

// helper function to get the decimal value of a hex digit
static int	get_decimal_value(char c, t_fdf *data)
{
	int	i;

	i = 0;
	while ("0123456789abcdef"[i] != c && "0123456789ABCDEF"[i] != c)
	{
		if (i == 16)
			ft_error("Invalid hex color value in map!", data);
		i++;
	}
	return (i);
}

/* 
Modified atoi that converts the chars from the map
into integers but also reads the hex color values
(if given) and puts them into the color-matrix 
(by dereferenced value of int* color)
*/
int	color_atoi(const char *str, int *color, t_fdf *data)
{
	int		result;
	int		nbrcounter;

	result = 0;
	while (is_whitespace(*str))
		str++;
	while (*str > 47 && *str < 58)
	{
		result *= 10;
		result += *str - 48;
		str++;
	}
	if (*str == 44 && *(str + 1) == 48 && *(str + 2) == 120)
	{	
		str += 3;
		*color = 0;
		nbrcounter = 1;
		while (*str != 0 && *str != 32 && *str != 10 && nbrcounter++ <= 6)
		{
			*color *= 16;
			*color += get_decimal_value(*str++, data);
		}
	}
	return (result);
}
