/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:42:27 by raweber           #+#    #+#             */
/*   Updated: 2022/08/05 07:57:19 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_exit_status = 0;

// initializes the minimal needed struct for minishell
static void	init_struct(t_cmd_struct **cmd_struct, char **envp)
{
	(*cmd_struct)->cur_env_size = get_array_size(envp) * 2;
	(*cmd_struct)->env_clone = copy_env(envp, (*cmd_struct));
	(*cmd_struct)->list_start = cmd_struct;
	(*cmd_struct)->fd_infile = 0;
	(*cmd_struct)->fd_outfile = 1;
	(*cmd_struct)->next = NULL;
}

// runs one iteration of minishell with prompt and execution
static int	run_minishell(t_cmd_struct *cmd_struct)
{
	char	*input;

	signal_interactive();
	cmd_struct->command_splitted = NULL;
	cmd_struct->command_path = NULL;
	input = NULL;
	input = prompt();
	if (!input)
		return (-1);
	if (!input[0])
	{
		g_exit_status = 0;
		return (1);
	}
	if (handle_input(cmd_struct, input) == -1)
		return (1);
	g_exit_status = 0;
	run_commands(cmd_struct);
	loop_clean_up(cmd_struct);
	return (0);
}

// main function for minishell
int	main(int argc, char **argv, char **envp)
{
	t_cmd_struct	*cmd_struct;
	int				minishell_status;

	if (argc > 1)
	{
		ft_printf("Error: No arguments required. Try %s\n", argv[0]);
		return (1);
	}
	cmd_struct = malloc(sizeof(t_cmd_struct));
	if (!cmd_struct)
	{
		ft_putstr_fd("Error: malloc failed in main", 2);
		exit(1);
	}
	init_struct(&cmd_struct, envp);
	while (1)
	{
		minishell_status = run_minishell(cmd_struct);
		if (minishell_status == -1)
			break ;
		else if (minishell_status == 1)
			continue ;
	}
	clean_up(cmd_struct);
}
