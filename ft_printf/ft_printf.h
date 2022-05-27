/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:12:37 by raweber           #+#    #+#             */
/*   Updated: 2022/05/09 19:12:30 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
char	*pointer_to_string(unsigned long int c);
int		process_string(char *c);
int		process_pointer(unsigned long int n);
int		process_decimal(int n);
int		process_unsigned_decimal(unsigned int n);
int		process_hex(unsigned int n, int flag);

#endif