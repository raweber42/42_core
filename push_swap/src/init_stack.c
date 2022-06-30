/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:44:59 by raweber           #+#    #+#             */
/*   Updated: 2022/06/16 18:12:45 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// helper for counting arguments if they are passed in a single string
int	count_str_arg(char **argv)
{
	char	**args;
	int		count;
	int		free_helper;

	args = ft_split(argv[1], ' ');
	count = 0;
	while (args[count])
		count++;
	free_helper = count;
	while (free_helper >= 0)
		free(args[free_helper--]);
	free(args);
	return (count);
}

/*
helper function to turn the numbers into their indexed values
example: [1, -100, 50, 4, 0] becomes [2, 0, 4, 3, 1]
*/
void	convert_int_arr(long *arr, int argc)
{
	int		i;
	int		j;
	long	*temp_arr;

	temp_arr = malloc(argc * sizeof(long));
	i = 0;
	while (i < argc - 1)
	{
		temp_arr[i] = 1;
		j = 0;
		while (j < argc - 1)
		{
			if (arr[i] > arr[j])
				temp_arr[i]++;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		arr[i] = temp_arr[i];
		i++;
	}
	free(temp_arr);
}

// initializes the stack a and populates it with the values given in argv
// also transfers the values to their index representation
void	init_stack(int argc, long *arr, char **argv, t_ps_list **bottom_a)
{
	int			i;
	int			temp;
	t_ps_list	*new_node;

	i = 0;
	while (i < argc - 1)
	{
		arr[i] = ps_atol(argv[i + 1], bottom_a);
		i++;
	}
	convert_int_arr(arr, argc);
	i = argc - 2;
	temp = arr[i];
	new_node = ps_lstnew(temp);
	*bottom_a = new_node;
	i--;
	while (i >= 0)
	{
		temp = arr[i];
		new_node = ps_lstnew(temp);
		ps_lstadd_back(bottom_a, new_node);
		i--;
	}
}

// SPECIAL CASE: Input has only one argument, a string with the numbers INSIDE
// initializes the stack a and populates it with the values given in argv
// also transfers the values to their index representation
void	init_stack_str(int argc, long *arr, char **argv, t_ps_list **bottom_a)
{
	int			i;
	int			temp;
	t_ps_list	*new_node;
	char		**args;

	args = ft_split(argv[1], ' ');
	i = 0;
	while (args[i])
	{
		arr[i] = ps_atol(args[i], bottom_a);
		i++;
	}
	free_args(args, i);
	convert_int_arr(arr, argc + 1);
	temp = arr[argc - 1];
	new_node = ps_lstnew(temp);
	*bottom_a = new_node;
	while (argc - 2 >= 0)
	{
		temp = arr[argc - 2];
		new_node = ps_lstnew(temp);
		ps_lstadd_back(bottom_a, new_node);
		argc--;
	}
}

void	free_args(char **args, int i)
{
	while (i >= 0)
		free(args[i--]);
	free(args);
}
