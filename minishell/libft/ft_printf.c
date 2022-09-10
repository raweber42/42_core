/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:58:43 by raweber           #+#    #+#             */
/*   Updated: 2022/05/19 19:40:18 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// detects the formatting flag and passes the value
// to the corresponding function 
int	format_handler(const char *str, int i, va_list args)
{
	int		length;
	char	c;

	length = 0;
	if (str[i] == 'c')
	{
		c = va_arg(args, int);
		length += write(1, &c, 1);
	}
	else if (str[i] == 's')
		length += process_string(va_arg(args, char *));
	else if (str[i] == 'p')
		length += process_pointer(va_arg(args, unsigned long int));
	else if (str[i] == 'd' || str[i] == 'i')
		length += process_decimal(va_arg(args, int));
	else if (str[i] == 'u')
		length += process_unsigned_decimal(va_arg(args, unsigned int));
	else if (str[i] == 'x')
		length += process_hex(va_arg(args, unsigned int), 0);
	else if (str[i] == 'X')
		length += process_hex(va_arg(args, unsigned int), 1);
	else if (str[i] == '%')
		length += write(1, "%", 1);
	return (length);
}

// reads all function arguments into args. If a % is encountered,
// the function calls the format_handler in order to format the output.
// Else just prints the characters of the string passed as the first argument.
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			length += format_handler(str, i, args);
		}
		else
		{
			length++;
			write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (length);
}

/////////////////////////
// #include <stdio.h>

// int main(void)
// {
// 	int c;
// 	char kara = 'b';
// 	char str[5] = "HELL";
// 	c = ft_printf("%x", -123);
// 	printf("length: %d ", c);
// }