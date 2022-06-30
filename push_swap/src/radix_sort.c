/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:26:11 by raweber           #+#    #+#             */
/*   Updated: 2022/06/14 20:59:21 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	run_radix_sort(t_ps_list **bottom_a, t_ps_list **bottom_b)
{
	int	max_number;
	int	max_bits;
	int	i;
	int	j;
	int	temp_num;

	max_number = ps_lstsize(bottom_a) - 1;
	max_bits = 0;
	while ((max_number >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < max_number + 1)
		{
			temp_num = get_top_of_stack(bottom_a);
			reverse_or_push(temp_num, i, bottom_a, bottom_b);
			j++;
		}
		i++;
		empty_stack_b(bottom_a, bottom_b);
	}
}

// if (i+1)-th bit is 1, leave in stack a
// otherwise push it to stack b
void	reverse_or_push(int temp_num, int i, t_ps_list **bottom_a,
							t_ps_list **bottom_b)
{
	if (((temp_num >> i) & 1) == 1)
	{
		ft_printf("ra\n");
		rotate_x(bottom_a);
	}
	else
	{	
		ft_printf("pb\n");
		push_x_to_y(bottom_a, bottom_b);
	}
}

// helper function to push all elements from b back to a
void	empty_stack_b(t_ps_list **bottom_a, t_ps_list **bottom_b)
{
	while (*bottom_b)
	{
		ft_printf("pa\n");
		push_x_to_y(bottom_b, bottom_a);
	}
}

// helper function to get to value of the top of a stack
int	get_top_of_stack(t_ps_list **bottom_x)
{
	t_ps_list	*temp_stack;

	temp_stack = *bottom_x;
	if (!temp_stack)
		return (-1);
	while (temp_stack->next)
		temp_stack = temp_stack->next;
	return (temp_stack->content);
}
