/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:49:48 by raweber           #+#    #+#             */
/*   Updated: 2022/06/14 16:57:11 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	is_stack_sorted_before(t_ps_list **bottom_x)
{
	t_ps_list	*temp_1;
	t_ps_list	*temp_2;
	int			sorted;

	sorted = 1;
	temp_1 = *bottom_x;
	while (temp_1->next != NULL)
	{
		temp_2 = temp_1->next;
		if (!(temp_1->content > temp_2->content))
			sorted = 0;
		temp_1 = temp_2;
	}
	if (sorted)
	{
		free_stack(bottom_x);
		exit(1);
	}
}

int	is_stack_sorted_during(t_ps_list **bottom_x)
{
	t_ps_list	*temp_1;
	t_ps_list	*temp_2;
	int			sorted;

	sorted = 1;
	temp_1 = *bottom_x;
	while (temp_1->next != NULL)
	{
		temp_2 = temp_1->next;
		if (!(temp_1->content > temp_2->content))
			sorted = 0;
		temp_1 = temp_2;
	}
	if (sorted)
		return (1);
	return (0);
}

void	check_for_duplicates(t_ps_list **bottom_x)
{	
	t_ps_list	*temp_1;
	t_ps_list	*temp_2;
	int			duplicate;

	duplicate = 0;
	temp_1 = *bottom_x;
	while (temp_1 != NULL)
	{
		temp_2 = temp_1->next;
		while (temp_2)
		{
			if (temp_1->content == temp_2->content)
			{	
				duplicate = 1;
				ps_error(bottom_x);
			}
			temp_2 = temp_2->next;
		}
		temp_1 = temp_1->next;
	}
}
