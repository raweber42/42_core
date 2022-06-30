/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:22:24 by raweber           #+#    #+#             */
/*   Updated: 2022/06/23 14:47:08 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

typedef struct s_pipex_list
{
	struct s_pipex_list	**list_start;
	char				**command_splitted;
	char				*command_path;
	int					fd_infile;
	int					fd_outfile;
	char				*filename;
	int					here_doc;
	struct s_pipex_list	*next;
}				t_pipex_list;

// main.c
void			pipe_loop(t_pipex_list *argument_ll, char **envp,
					int previous_exists);

// error.c
int				pipex_error(char *err_msg, t_pipex_list *argument_ll);
void			destroy_linked_list(t_pipex_list **list_start);

// init_linked_list.c
void			init_linked_list(t_pipex_list **head, int argc,
					char **argv, char **envp);
t_pipex_list	*pipex_lstnew(char **argv, int argc,
					char **envp, int current_argc);
void			pipex_lstadd_back(t_pipex_list **lst,
					t_pipex_list *new_node);

// helpers.c
char			**get_paths(char **envp);
int				get_fd_infile(char *filename, t_pipex_list *argument_ll);
int				get_fd_outfile(t_pipex_list *argument_ll);
void			set_command_path(char **envp, t_pipex_list *command_struct);
char			*pipex_strjoin(char *s1, char *s2);

// redirect.c
void			redirect_child(int *old_fds, int *new_fds,
					t_pipex_list *argument_ll, int previous_command_exists);
void			redirect_parent(int *old_fds, int *new_fds,
					t_pipex_list *argument_ll, int previous_command_exists);

// run_command.c
void			run_execve(t_pipex_list *command_struct_child, char **envp);

// here_doc.c
void			run_here_doc(t_pipex_list **argument_ll, char **argv);

#endif