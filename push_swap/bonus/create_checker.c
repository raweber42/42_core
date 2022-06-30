/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 09:11:12 by raweber           #+#    #+#             */
/*   Updated: 2022/06/24 10:42:49 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	check_for_duplicates(&bottom_a);
	get_commands(&bottom_a, &bottom_b);
	is_stack_sorted_during(&bottom_a);
	free_stack(&bottom_a);
	free_stack(&bottom_b);
	return (0);
}

// reads the commands given as output from push_swap program
void	get_commands(t_ps_list **bottom_a, t_ps_list **bottom_b)
{
	char	*current_command;

	current_command = get_next_line(STDIN_FILENO);
	while (current_command)
	{
		execute_command(current_command, bottom_a, bottom_b);
		free(current_command);
		current_command = get_next_line(STDIN_FILENO);
	}
	ft_putstr_fd(current_command, 2);
	free(current_command);
	if (is_stack_sorted_during(bottom_a))
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
}

// executes command or throws error, if the command is invalid
void	execute_command(char *current_command,
		t_ps_list **bottom_a, t_ps_list **bottom_b)
{
	if (ft_strncmp(current_command, "pb\n", 3) == 0)
		push_x_to_y(bottom_a, bottom_b);
	else if (ft_strncmp(current_command, "pa\n", 3) == 0)
		push_x_to_y(bottom_b, bottom_a);
	else if (ft_strncmp(current_command, "sa\n", 3) == 0)
		swap_x(bottom_a);
	else if (ft_strncmp(current_command, "sb\n", 3) == 0)
		swap_x(bottom_b);
	else if (ft_strncmp(current_command, "ss\n", 3) == 0)
		swap_both(bottom_b, bottom_a);
	else if (ft_strncmp(current_command, "ra\n", 3) == 0)
		rotate_x(bottom_a);
	else if (ft_strncmp(current_command, "rb\n", 3) == 0)
		rotate_x(bottom_b);
	else if (ft_strncmp(current_command, "rr\n", 3) == 0)
		rotate_both(bottom_b, bottom_a);
	else if (ft_strncmp(current_command, "rra\n", 3) == 0)
		reverse_rotate_x(bottom_a);
	else if (ft_strncmp(current_command, "rrb\n", 3) == 0)
		reverse_rotate_x(bottom_b);
	else if (ft_strncmp(current_command, "rrr\n", 3) == 0)
		reverse_rotate_both(bottom_a, bottom_b);
	else
		ps_error_bonus(bottom_a, bottom_b);
}

// Displays an error and exits the program
int	ps_error_bonus(t_ps_list **bottom_a, t_ps_list **bottom_b)
{
	free_stack(bottom_a);
	free_stack(bottom_b);
	write(2, "Error\n", 6);
	exit(1);
}

// $>./checker "" 1 Error
// $>