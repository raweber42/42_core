/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:59:43 by raweber           #+#    #+#             */
/*   Updated: 2022/06/25 12:00:25 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
for stacks smaller than 6 the cases are being hardcoded in order to meet
the performance requirements
Size 2   -> swap the elements (they are unordered)
Size 3-6 -> push to b until only three elements left, sort them and then 
			rotate a to the right position to push it back in the right position
*/
void	run_small_stack_sort(t_ps_list **bottom_a, t_ps_list **bottom_b)
{
	if (ps_lstsize(bottom_a) == 2)
	{
		swap_x(bottom_a);
		ft_printf("sa\n");
	}
	else
	{
		sort_small(bottom_a, bottom_b);
	}
}

// first part of sorting: pushing to b and sorting remaining three elements
void	sort_small(t_ps_list **bottom_a, t_ps_list **bottom_b)
{
	int	original_size;

	original_size = ps_lstsize(bottom_a);
	while (ps_lstsize(bottom_a) > 3)
	{
		push_x_to_y(bottom_a, bottom_b);
		ft_printf("pb\n");
	}
	sort_three(bottom_a);
	if (*bottom_b && (*bottom_b)->next)
	{
		if ((*bottom_b)->content > (*bottom_b)->next->content)
		{
			swap_x(bottom_b);
			ft_printf("sb\n");
		}
	}
	sort_small_2(bottom_a, bottom_b, original_size);
}

// second part of sorting: rotate a to right place and 
// push element from stack b in right position
void	sort_small_2(t_ps_list **bottom_a, t_ps_list **bottom_b, int list_size)
{
	int	temp;
	int	rotate_direction;

	rotate_direction = 0;
	while (ps_lstsize(bottom_a) < list_size)
	{
		temp = rotate_to_insert_place(bottom_a, bottom_b);
		push_x_to_y(bottom_b, bottom_a);
		ft_printf("pa\n");
		rotate_direction = get_rotate_direction(bottom_a, bottom_b, temp);
		if (rotate_direction == 2147483647)
		{
			rotate_x(bottom_a);
			ft_printf("ra\n");
			continue ;
		}
	}
	rotate_back(bottom_a, rotate_direction);
}

// rotates according to given direction
void	rotate_back(t_ps_list **bottom_a, int rotate_direction)
{
	while (!is_stack_sorted_during(bottom_a))
	{
		if (rotate_direction == 1)
		{
			rotate_x(bottom_a);
			ft_printf("ra\n");
		}
		else
		{
			reverse_rotate_x(bottom_a);
			ft_printf("rra\n");
		}
	}
}

// hardcodes all posibilities for sorting a stack of three
void	sort_three(t_ps_list **bottom_a)
{
	if ((*bottom_a)->content > (*bottom_a)->next->content
		&& (*bottom_a)->next->content < (*bottom_a)->next->next->content
		&& (*bottom_a)->content > (*bottom_a)->next->next->content)
	{
		swap_x(bottom_a);
		ft_printf("sa\n");
	}
	else if ((*bottom_a)->content < (*bottom_a)->next->content
		&& (*bottom_a)->next->content > (*bottom_a)->next->next->content
		&& (*bottom_a)->content > (*bottom_a)->next->next->content)
	{
		swap_x(bottom_a);
		ft_printf("sa\n");
		rotate_x(bottom_a);
		ft_printf("ra\n");
	}
	else if ((*bottom_a)->content > (*bottom_a)->next->content
		&& (*bottom_a)->next->content < (*bottom_a)->next->next->content
		&& (*bottom_a)->content < (*bottom_a)->next->next->content)
	{
		rotate_x(bottom_a);
		ft_printf("ra\n");
	}
	else
		sort_three_2(bottom_a);
}
