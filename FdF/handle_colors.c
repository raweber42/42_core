/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:04:33 by raweber           #+#    #+#             */
/*   Updated: 2022/05/31 11:39:12 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

// helper function to get the sign of the number
static int	read_color(const char *str, t_fdf *data)
{
	int	color;
	int	nbrcounter;

	str += 3;
	color = 0;
	nbrcounter = 1;
	while (*str != 0 && *str != 32 && *str != 10 && nbrcounter++ <= 6)
	{
		color *= 16;
		color += get_decimal_value(*str++, data);
	}
	return (color);
}

/* 
Modified atoi that converts the chars from the map
into integers but also reads the hex color values
(if given) and puts them into the color-matrix 
(by dereferenced value of int* color). If no hex value
is given by the map, the default color will be assigned.
*/
int	color_atoi(const char *str, int *color, t_fdf *data)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!ft_isdigit(*str))
		ft_error("Error: map contains non-integer values.", data);
	while (*str > 47 && *str < 58)
	{
		result *= 10;
		result += *str - 48;
		str++;
	}
	*color = data->default_color;
	if (*str == 44 && *(str + 1) == 48 && *(str + 2) == 120)
		*color = read_color(str, data);
	return (sign * result);
}
