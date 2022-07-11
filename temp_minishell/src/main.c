/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:42:27 by raweber           #+#    #+#             */
/*   Updated: 2022/07/10 16:42:13 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	TESTING_fill_command_struct(t_cmd_struct *cmd_struct, char **envp)
{
	char **argv = malloc(10 * sizeof(char *));
	argv[0] = "./minishell";
	argv[1] = "ls -la";
	argv[2] = "pwd";

	
	cmd_struct->cur_env_size = get_env_size(envp) * 2;
	cmd_struct->env_clone = copy_env(envp, cmd_struct);
	
	if (cmd_struct->env_clone == NULL)
		return ; // errror handling here!
	cmd_struct->command_nbr = 0;
	cmd_struct->is_last_command = 0;	
	cmd_struct->command_splitted = ft_split(argv[1], 32);
	set_command_path(envp, cmd_struct);
	//printf("command_path 1: %s\n", cmd_struct->command_path);
	cmd_struct->fd_infile = 0; // STDIN_FILENO
	cmd_struct->fd_outfile = 1; // STDOUT_FILENO
	//HEREDOC?FILENAME?
	
	cmd_struct->cur_env_size = get_env_size(envp) * 2;
	cmd_struct->next->env_clone = copy_env(envp, cmd_struct);
	if (cmd_struct->env_clone == NULL)
		return ; // errror handling here!
	cmd_struct->next->command_nbr = 1;
	cmd_struct->next->is_last_command = 1;
	cmd_struct->next->command_splitted = ft_split(argv[2], 32);
	set_command_path(envp, cmd_struct->next); // adjust this to envp_clone instead of normal env?
	//printf("command_path 2: %s\n", cmd_struct->next->command_path);
	
	cmd_struct->next->fd_infile = 0;
	cmd_struct->next->fd_outfile = 1;
	cmd_struct->next->next = NULL;
}


int main(int argc, char **argv, char **envp)
{
	t_cmd_struct	*cmd_struct;
	char			*input;
	
	if (argc > 1)
	{
		ft_printf("Error: No arguments required. Try %s\n", argv[0]);
		return (1);
	}

	//#####################
	// SIGNAL HANDLING
	// ALINA INPUT HANDLING FUNCTIONS
	// init_linked_list(&cmd_struct, argc, argv, envp);
	// ####################
	
	while (1)
	{
		cmd_struct = NULL;
		//#####################
		input = NULL;
		// ALINA INPUT HANDLING FUNCTIONS
		// input = prompt();
		//			^
		//			|
		// handle empty input here
		// ft_printf("The input is: %s\n", input);
		//check_input();
		//#####################
		cmd_struct = malloc(sizeof(t_cmd_struct));
		cmd_struct->next = malloc(sizeof(t_cmd_struct));
		TESTING_fill_command_struct(cmd_struct, envp);
		run_commands(cmd_struct);
		return (0); // remove this!
	}
	envp = NULL;
}