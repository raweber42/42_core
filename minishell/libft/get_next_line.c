/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:46:26 by raweber           #+#    #+#             */
/*   Updated: 2022/05/19 19:51:04 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// secured version of stringjoin to prevent memory leaks
// works also as strdup if the first argument is zero
char	*my_str_join(char *result, char *temp)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_string = malloc(ft_strlen(result) + ft_strlen(temp) + 1);
	if (new_string == 0)
		return (NULL);
	if (result)
	{
		while (result[i])
		{	
			new_string[i] = result[i];
			i++;
		}
		free(result);
	}
	while (temp[j])
		new_string[i++] = temp[j++];
	new_string[i] = '\0';
	return (new_string);
}

// formats the output so that it only prints until \n (included)
char	*make_line(char *result, int bytes_read)
{
	int		i;
	char	*line;

	if (!result)
		return (NULL);
	if (!bytes_read && !ft_strchr(result, '\n'))
		return (result);
	i = 0;
	while (result[i] != '\n')
		i++;
	line = ft_substr(result, 0, i + 1);
	free(result);
	return (line);
}

// temp is edited (by copying it to another array) the beginning 
// up until the next newline character is cut off
// if there is no newline character left over, temp[0] can be set to zero
// in order to signal that all work with temp has been done.
void	edit_temp(char *temp)
{
	int		i;
	char	copy[BUFFER_SIZE + 1];

	copy[BUFFER_SIZE] = 0;
	i = 0;
	while (i < BUFFER_SIZE)
		copy[i++] = '\0';
	ft_strcpy(copy, temp);
	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (i == BUFFER_SIZE && temp[i] == 0)
		temp[0] = 0;
	else
		ft_strcpy(temp, &copy[i + 1]);
	return ;
}

// subfunction to update the result according to
// whether there is something left in temp or not
char	*update_result(char *result, char *temp)
{
	char	*new_result;

	if (result == NULL)
		new_result = my_str_join(0, temp);
	else
		new_result = my_str_join(result, temp);
	return (new_result);
}

// gnl reads from a given file descriptor a given BUFFER_SIZE to
// a static buffer array called temp. If there is data left in temp
// from the last iteration, it will first be added to result. 
// The read bytes get also added to result.
// If there is nothing left to read (and in temp), or reading was not 
// possible, NULL is returned.
char	*get_next_line(int fd)
{
	char			*result;
	int				bytes_read;
	static char		temp[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	if (temp[0] != 0)
		result = ft_strdup(temp);
	temp[BUFFER_SIZE] = '\0';
	while (!ft_strchr(result, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (!bytes_read)
			break ;
		else if (bytes_read == -1)
			return (NULL);
		if (bytes_read < BUFFER_SIZE)
			temp[bytes_read] = '\0';
		result = update_result(result, temp);
	}
	edit_temp(temp);
	if (!bytes_read && !temp[0] && !result)
		return (NULL);
	return (make_line(result, bytes_read));
}
