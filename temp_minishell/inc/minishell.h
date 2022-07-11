/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:43:34 by raweber           #+#    #+#             */
/*   Updated: 2022/07/10 17:07:49 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>


// handle linux??? 


typedef struct s_cmd_struct
{
	struct s_cmd_struct	**list_start;
	int					command_nbr; // add this in init
	int					is_last_command; // add this in init
	char				**command_splitted;
	//char				command_splitted[3][3];
	char				*command_path;
	char				**env_clone; // add this in init
	int					cur_env_size; // SET THIS! (can get set outside of init maybe?)
	int					fd_infile;
	int					fd_outfile;
	char				*filename; // check, if needed
	int					here_doc; // check, if needed
	struct s_cmd_struct	*next;
}				t_cmd_struct;

void	init_linked_list(t_cmd_struct **cmd_struct, int argc, char **argv, char **envp);
char	*prompt(void);
void	run_commands(t_cmd_struct *cmd_struct);
void	redirect_parent(int *old_fds, int *new_fds,
			t_cmd_struct *cmd_struct, int previous_command_exists);
void	redirect_child(int *old_fds, int *new_fds,
			t_cmd_struct *cmd_struct, int previous_command_exists);
void	ms_error(char *message, t_cmd_struct *cmd_struct);

// helpers.c
char	**get_paths(char **envp);
int		get_fd_infile(char *filename, t_cmd_struct *cmd_struct);
int		get_fd_outfile(t_cmd_struct *cmd_struct);
void	set_command_path(char **envp, t_cmd_struct *cmd_struct);
char	*pipex_strjoin(char *s1, char *s2);

// init.c
int	get_env_size(char **envp);
char	**copy_env(char **envp, t_cmd_struct *cmd_struct);


// check_builtin.c
int	check_builtin(t_cmd_struct *cmd_struct);


// builtin_pwd.c
void	builtin_pwd(void);
// builtin_cd.c
void	builtin_cd(t_cmd_struct *cmd_struct);
// builtin_echo.c

// builtin_export.c

// builtin_env.c

// builtin_unset.c

// builtin_exit.c

#endif