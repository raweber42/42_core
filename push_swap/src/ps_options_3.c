/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_options_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:20:03 by raweber           #+#    #+#             */
/*   Updated: 2022/06/25 15:52:32 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// pushes the top element of stack_x on top of stack_y
void	push_x_to_y(t_ps_list **bottom_x, t_ps_list **bottom_y)
{
	t_ps_list	*last_x;
	t_ps_list	*second_last_x;
	t_ps_list	*last_y;

	if (*bottom_x == NULL)
		return ;
	last_y = set_last_y(bottom_y);
	if (one_element_on_x(bottom_x, bottom_y, last_y))
		return ;
	second_last_x = *bottom_x;
	while (second_last_x->next->next != NULL)
		second_last_x = second_last_x->next;
	last_x = second_last_x->next;
	second_last_x->next = NULL;
	if (last_y == NULL)
	{
		*bottom_y = last_x;
		return ;
	}
	last_y->next = last_x;
}

// helper for the case that there is only one element on x-stack
int	one_element_on_x(t_ps_list **bottom_x, t_ps_list **bottom_y,
		t_ps_list *last_y)
{
	if ((*bottom_x)->next == NULL)
	{
		if (last_y)
			last_y->next = (*bottom_x);
		else
			*bottom_y = (*bottom_x);
		*bottom_x = NULL;
		return (1);
	}
	return (0);
}

// helper function to safe lines for push_x_to_y
t_ps_list	*set_last_y(t_ps_list **bottom_y)
{
	t_ps_list	*last_y;

	if (*bottom_y == NULL)
		last_y = NULL;
	else
		last_y = *bottom_y;
	while (last_y && last_y->next != NULL)
		last_y = last_y->next;
	return (last_y);
}
