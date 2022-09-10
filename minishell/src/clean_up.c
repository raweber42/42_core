/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:28:18 by raweber           #+#    #+#             */
/*   Updated: 2022/08/05 08:02:24 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// helper for freeing stuff
void	loop_helper(t_cmd_struct *temp)
{
	int				i;

	i = 0;
	while (temp->env_clone && temp->env_clone[i])
		free(temp->env_clone[i++]);
	free(temp->env_clone);
	free(temp);
}

// free's up everything but the first element of the struct
void	loop_clean_up(t_cmd_struct *cmd_struct)
{
	t_cmd_struct	*temp;
	t_cmd_struct	*next;

	temp = (*cmd_struct->list_start);
	while (temp)
	{
		next = temp->next;
		free_double_array(temp->command_splitted);
		if (temp->command_path)
			free(temp->command_path);
		if (temp->fd_infile != STDIN_FILENO)
			close(temp->fd_infile);
		if (temp->fd_outfile != STDOUT_FILENO)
			close(temp->fd_outfile);
		if (temp != (*(cmd_struct->list_start)))
			loop_helper(temp);
		temp = next;
	}
	(*cmd_struct->list_start)->next = NULL;
}

void	clean_up(t_cmd_struct *cmd_struct)
{
	int				i;
	t_cmd_struct	*temp;
	t_cmd_struct	*next;

	temp = (*cmd_struct->list_start);
	while (temp)
	{
		next = temp->next;
		free_double_array(temp->command_splitted);
		if (temp->command_path)
			free(temp->command_path);
		i = 0;
		while (temp->env_clone && temp->env_clone[i] && i < temp->cur_env_size)
			free(temp->env_clone[i++]);
		if (temp->env_clone)
			free(temp->env_clone);
		if (temp->fd_infile != STDIN_FILENO)
			close(temp->fd_infile);
		if (temp->fd_outfile != STDOUT_FILENO)
			close(temp->fd_outfile);
		free(temp);
		temp = next;
	}
	rl_clear_history();
}

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	if (array)
		free(array);
}
