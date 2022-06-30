/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_options_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:55:08 by raweber           #+#    #+#             */
/*   Updated: 2022/06/25 11:20:26 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate both stacks
void	rotate_both(t_ps_list **bottom_a, t_ps_list **bottom_b)
{
	rotate_x(bottom_a);
	rotate_x(bottom_b);
}

// move top of stack_x to bottom of stack_x
void	rotate_x(t_ps_list **bottom_x)
{
	t_ps_list	*last;
	t_ps_list	*second_last;

	if (!bottom_x || !(*bottom_x)->next)
		return ;
	second_last = *bottom_x;
	while (second_last->next->next != NULL)
	{
		second_last = second_last->next;
	}
	last = second_last->next;
	second_last->next = NULL;
	last->next = *bottom_x;
	*bottom_x = last;
}

// reverse rotate both stacks
void	reverse_rotate_both(t_ps_list **bottom_a, t_ps_list **bottom_b)
{
	reverse_rotate_x(bottom_a);
	reverse_rotate_x(bottom_b);
	ft_printf("rrr\n");
}

// move bottom of stack_x to top of stack_x
void	reverse_rotate_x(t_ps_list **bottom_x)
{
	t_ps_list	*first;
	t_ps_list	*second;
	t_ps_list	*last;

	if (!bottom_x || !(*bottom_x)->next)
		return ;
	first = (*bottom_x);
	second = (*bottom_x)->next;
	last = second;
	while (last->next)
	{
		last = last->next;
	}
	last->next = *bottom_x;
	*bottom_x = second;
	first->next = NULL;
}
