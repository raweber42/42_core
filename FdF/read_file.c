/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:54:34 by raweber           #+#    #+#             */
/*   Updated: 2022/05/29 19:34:20 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_elements(char *str)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != 32 && (str[i + 1] == 32 || \
							str[i + 1] == '\0' || str[i + 1] == '\n'))
			counter++;
		i++;
	}
	return (counter);
}

/*
Calls get_next_line until it returns zero and counts 
the number of rows in the given file.
*/
int	get_height(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("Error while trying to read file.", data);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

/*
Calls get_next_line once and determines the number
of elements in the string skipping whitespace.
Then goes through all lines and checks that they 
all have the same width.
*/
int	get_width(char *filename, t_fdf *data)
{
	int		fd;
	char	*str;
	int		element_count;
	int		count_check;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error while trying to read file.", data);
	str = get_next_line(fd);
	if (!str)
		ft_error("Error: Empty file!", data);
	element_count = count_elements(str);
	while (str)
	{
		count_check = count_elements(str);
		free(str);
		if (count_check != element_count)
			ft_error("Error in map: Lines don't have the same width!", data);
		str = get_next_line(fd);
	}
	close(fd);
	return (element_count);
}

/*
Splits every line into an array of elements, converts them
into integers and adds them to the z_matrix. Also handles
hex colors, if they are given in the map.
*/
void	fill_matrix(int *z_line, int *color_line, char *line, t_fdf *data)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = color_atoi(nums[i], &color_line[i], data);
		i++;
	}
	while (i >= 0)
	{
		free(nums[i]);
		i--;
	}
	free(nums);
}

/*
Allocates memory for the z- and color-matrix and
calls subfunctions to fill them.
*/
void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name, data);
	data->width = get_width(file_name, data);
	if (data->height <= 1 && data->width <= 1)
		ft_error("Error: Map has not enough elements to display.", data);
	allocate_matrixes(data);
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(data->z_matrix[i], data->color_matrix[i], line, data);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}
