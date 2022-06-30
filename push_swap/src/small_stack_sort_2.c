/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:33:58 by raweber           #+#    #+#             */
/*   Updated: 2022/06/25 15:51:55 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// second part of hardcoding all posibilities, need to safe lines
void	sort_three_2(t_ps_list **bottom_a)
{
	if ((*bottom_a)->content < (*bottom_a)->next->content
		&& (*bottom_a)->next->content < (*bottom_a)->next->next->content
		&& (*bottom_a)->content < (*bottom_a)->next->next->content)
	{
		rotate_x(bottom_a);
		ft_printf("ra\n");
		swap_x(bottom_a);
		ft_printf("sa\n");
	}
	else if ((*bottom_a)->content < (*bottom_a)->next->content
		&& (*bottom_a)->next->content > (*bottom_a)->next->next->content
		&& (*bottom_a)->content < (*bottom_a)->next->next->content)
	{
		reverse_rotate_x(bottom_a);
		ft_printf("rra\n");
	}
}

// calculates which way it takes less operation to rotate in the right place
int	get_rotate_direction(t_ps_list **bottom_a, t_ps_list **bottom_b, int lowest)
{
	int			counter;
	t_ps_list	*temp_a;
	int			top_of_b;

	if (lowest == 2147483647)
		return (2147483647);
	counter = 0;
	temp_a = *bottom_a;
	top_of_b = get_top_of_stack(bottom_b);
	while (temp_a && temp_a->content - top_of_b != lowest)
	{
		counter++;
		temp_a = temp_a->next;
	}
	if (counter > (ps_lstsize(bottom_a) / 2))
		return (0);
	else
		return (1);
}

// rotates the stack so that afterwards the top element of stack b can be
// pushed on the element that is the least bigger than the top of stack b
int	rotate_to_insert_place(t_ps_list **bottom_a, t_ps_list **bottom_b)
{
	t_ps_list	*temp_a;
	int			top_of_b;
	int			top_of_a;
	int			lowest;
	int			rotate_flag;

	top_of_b = get_top_of_stack(bottom_b);
	top_of_a = get_top_of_stack(bottom_a);
	temp_a = *bottom_a;
	lowest = 2147483647;
	while (temp_a)
	{
		if (((temp_a->content - top_of_b) < lowest)
			&& (temp_a->content > top_of_b))
			lowest = temp_a->content - top_of_b;
		temp_a = temp_a->next;
	}
	if (lowest == 2147483647)
		return (lowest);
	rotate_flag = get_rotate_direction(bottom_a, bottom_b, lowest);
	while (get_top_of_stack(bottom_a) - top_of_b != lowest)
	{
		rotate_to_lowest(bottom_a, rotate_flag);
	}
	return (lowest);
}

// rotates the stack according to the given direction
void	rotate_to_lowest(t_ps_list **bottom_a, int rotate_flag)
{
	if (rotate_flag == 1)
	{
		reverse_rotate_x(bottom_a);
		ft_printf("rra\n");
	}
	else
	{
		rotate_x(bottom_a);
		ft_printf("ra\n");
	}
}
