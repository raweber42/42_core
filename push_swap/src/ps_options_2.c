/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_options_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:42:48 by raweber           #+#    #+#             */
/*   Updated: 2022/06/25 11:20:44 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap both stacks
void	swap_both(t_ps_list **bottom_x, t_ps_list **bottom_y)
{
	swap_x(bottom_x);
	swap_x(bottom_y);
}

// swap first (top) two elements of x_stack
void	swap_x(t_ps_list **bottom_x)
{
	t_ps_list	*third_last;
	t_ps_list	*second_last;
	t_ps_list	*last;

	if (!bottom_x || !(*bottom_x)->next)
		return ;
	third_last = *bottom_x;
	second_last = third_last->next;
	last = second_last->next;
	if (third_last->next->next)
		while (third_last->next->next->next)
			move_on_stack(&third_last, &second_last, &last);
	if (last == NULL)
	{
		*bottom_x = second_last;
		second_last->next = third_last;
		third_last->next = NULL;
	}
	else
	{
		third_last->next = last;
		second_last->next = NULL;
		last->next = second_last;
	}
}

// helper function to safe lines for swap_x
void	move_on_stack(t_ps_list **third_last, t_ps_list **second_last,
						t_ps_list **last)
{
	*third_last = (*third_last)->next;
	*second_last = (*third_last)->next;
	*last = (*second_last)->next;
}

// frees the whole stack given as argument
void	free_stack(t_ps_list **bottom_x)
{
	t_ps_list	*temp1;

	while (*bottom_x != NULL)
	{
		temp1 = (*bottom_x)->next;
		free(*bottom_x);
		*bottom_x = temp1;
	}
}
