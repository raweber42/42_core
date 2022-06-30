/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:58:19 by raweber           #+#    #+#             */
/*   Updated: 2022/06/25 16:07:56 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// // helper function that visualizes the current state of the stack
// void	test_print(t_ps_list **bottom_a, t_ps_list **bottom_b)
// {
// 	int			lst_size;
// 	int			tmp_lst_size;
// 	t_ps_list	*temp_bottom_a = NULL;
// 	t_ps_list	*temp_bottom_b = NULL;

// 	int	lst_size_a = ps_lstsize(bottom_a);
// 	int	lst_size_b = ps_lstsize(bottom_b);
// 	if (lst_size_a > lst_size_b)
// 		lst_size = lst_size_a;
// 	else
// 		lst_size = lst_size_b;

// 	ft_printf("\n-----------------------------\n");
// 	ft_printf("Print the stacks from bottom:\n");
// 	int i = 0;

// 	while (*bottom_a != temp_bottom_a || *bottom_b != temp_bottom_b)
// 	{
// 		tmp_lst_size = lst_size - i;
// 		temp_bottom_a = *bottom_a;
// 		temp_bottom_b = *bottom_b;
// 		while (tmp_lst_size > 0)
// 		{
// 			if (temp_bottom_a)
// 				temp_bottom_a = temp_bottom_a->next;
// 			if (temp_bottom_b)
// 				temp_bottom_b = temp_bottom_b->next;
// 			tmp_lst_size--;
// 		}
// 		if (temp_bottom_a)
// 			ft_printf("%d", temp_bottom_a->content);
// 		ft_printf("\t");
// 		if (temp_bottom_b)
// 			ft_printf("%d", temp_bottom_b->content);
// 		ft_printf("\n");
// 		i++;
// 	}
// 	ft_printf("-\t-\na\tb\n\n");
// 	ft_printf("-----------------------------\n\n");
// }

// takes several arguments as input (also all in one string possible)
int	main(int argc, char **argv)
{
	t_ps_list	*bottom_a;
	t_ps_list	*bottom_b;
	long		*arr;

	if (argc == 1)
		return (0);
	bottom_a = NULL;
	bottom_b = NULL;
	if (argc == 2 && ft_strchr(argv[1], 32))
	{
		arr = malloc(count_str_arg(argv) * sizeof(long));
		init_stack_str(count_str_arg(argv), arr, argv, &bottom_a);
	}
	else
	{
		arr = malloc(argc * sizeof(long));
		init_stack(argc, arr, argv, &bottom_a);
	}
	free(arr);
	is_stack_sorted_before(&bottom_a);
	check_for_duplicates(&bottom_a);
	run_sort(&bottom_a, &bottom_b);
	free_stack(&bottom_a);
	free_stack(&bottom_b);
}

void	run_sort(t_ps_list **bottom_a, t_ps_list **bottom_b)
{
	if (ps_lstsize(bottom_a) < 6)
		run_small_stack_sort(bottom_a, bottom_b);
	else
		run_radix_sort(bottom_a, bottom_b);
}
