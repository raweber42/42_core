/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:16:54 by raweber           #+#    #+#             */
/*   Updated: 2022/06/14 16:17:55 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Displays an error and exits the program
int	ps_error(t_ps_list **bottom_a)
{
	free_stack(bottom_a);
	write(2, "Error\n", 6);
	exit(1);
}

// change error message to "Error\n"
// how do I make sure to free all the memory???