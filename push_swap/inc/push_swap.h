/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:58:43 by raweber           #+#    #+#             */
/*   Updated: 2022/06/25 16:08:06 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_ps_list
{
	int					content;
	int					bucket;
	struct s_ps_list	*next;
}					t_ps_list;

// main.c
// void		test_print(t_ps_list **bottom_a, t_ps_list **bottom_b);
void		run_sort(t_ps_list **bottom_a, t_ps_list **bottom_b);

// list_helpers.c
t_ps_list	*ps_lstnew(int content);
int			ps_lstsize(t_ps_list **lst);
void		ps_lstadd_front(t_ps_list **lst, t_ps_list *new);
void		ps_lstadd_back(t_ps_list **lst, t_ps_list *new);

// init_stack.c
void		init_stack(int argc, long *arr, char **argv, t_ps_list **bottom_a);
void		init_stack_str(int argc, long *arr, char **argv,
				t_ps_list **bottom_a);
void		convert_int_arr(long *arr, int argc);
int			count_str_arg(char **argv);
void		free_args(char **args, int i);

// ps_options.c
void		rotate_x(t_ps_list **bottom_x);
void		rotate_both(t_ps_list **bottom_a, t_ps_list **bottom_b);
void		push_x_to_y(t_ps_list **bottom_x, t_ps_list **bottom_y);
void		reverse_rotate_x(t_ps_list **bottom_x);
void		reverse_rotate_both(t_ps_list **bottom_a, t_ps_list **bottom_b);
void		swap_x(t_ps_list **bottom_x);
void		swap_both(t_ps_list **bottom_x, t_ps_list **bottom_y);
void		move_on_stack(t_ps_list **third_last,
				t_ps_list **second_last, t_ps_list **last);
t_ps_list	*set_last_y(t_ps_list **bottom_y);
void		free_stack(t_ps_list **bottom_x);
int			one_element_on_x(t_ps_list **bottom_x, t_ps_list **bottom_y,
				t_ps_list *last_y);

// check_stack.c
void		check_for_duplicates(t_ps_list **bottom_x);
void		is_stack_sorted_before(t_ps_list **bottom_x);
int			is_stack_sorted_during(t_ps_list **bottom_x);

// ps_atol.c
long		ps_atol(const char *str, t_ps_list **bottom_a);

// ps_error.c
int			ps_error(t_ps_list **bottom_a);

// radix sort functions
void		run_radix_sort(t_ps_list **bottom_a, t_ps_list **bottom_b);
int			get_top_of_stack(t_ps_list **bottom_x);
void		empty_stack_b(t_ps_list **bottom_a, t_ps_list **bottom_b);
void		reverse_or_push(int temp_num, int i,
				t_ps_list **bottom_a, t_ps_list **bottom_b);

// sorting small stacks
void		run_small_stack_sort(t_ps_list **bottom_a, t_ps_list **bottom_b);
void		sort_small(t_ps_list **bottom_a, t_ps_list **bottom_b);
void		sort_small_2(t_ps_list **bottom_a,
				t_ps_list **bottom_b, int original_size);
void		rotate_back(t_ps_list **bottom_a, int rotate_direction);
void		sort_three(t_ps_list **bottom_a);
void		sort_three_2(t_ps_list **bottom_a);
int			get_rotate_direction(t_ps_list **bottom_a,
				t_ps_list **bottom_b, int lowest);
int			rotate_to_insert_place(t_ps_list **bottom_a, t_ps_list **bottom_b);
void		rotate_to_lowest(t_ps_list **bottom_a, int rotate_flag);

// bonus/create_checker.c
int			main(int argc, char **argv);
void		get_commands(t_ps_list **bottom_a, t_ps_list **bottom_b);
void		execute_command(char *current_command,
				t_ps_list **bottom_a, t_ps_list **bottom_b);
int			ps_error_bonus(t_ps_list **bottom_a, t_ps_list **bottom_b);

#endif