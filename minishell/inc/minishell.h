/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:43:34 by raweber           #+#    #+#             */
/*   Updated: 2022/08/04 16:38:41 by raweber          ###   ########.fr       */
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
# include <errno.h>
# include <signal.h>
# include <sys/wait.h>
# include <stdbool.h>

# ifdef __linux__
// Linux
#  define PATH_SIZE 4096
# else
// Mac
#  define PATH_SIZE 1024
# endif

# define READ_END 0
# define WRITE_END 1

extern int	g_exit_status;

typedef struct s_cmd_struct
{
	struct s_cmd_struct	**list_start;
	int					command_nbr;
	char				**command_splitted;
	char				*command_path;
	char				**env_clone;
	int					cur_env_size;
	int					fd_infile;
	int					fd_outfile;
	struct s_cmd_struct	*next;
}				t_cmd_struct;

typedef struct s_token
{
	char			*string;
	int				type;
	struct s_token	*next;
}					t_token;

enum	e_token_types
{
	WORD,
	SEP,
	PIPE,
	IN_RED,
	OUT_RED,
	HERE_DOC,
	APPEND_RED,
};

//------------PARSING----------------//
// par_interpret_utils.c
t_cmd_struct	*create_new(t_cmd_struct *cmd, int *c);
int				count_args(t_token **token_list);
void			init_cmd_node(t_cmd_struct *cmd, t_token **tkn, int cmd_count);

// lex_check_redir.c
int				check_redirections(char *s);
int				check_single_inredir(char *s, int *i);
int				check_single_outredir(char *s, int *i);
int				check_double_inredir(char *s, int *i);
int				check_double_outredir(char *s, int *i);

// lex_check.c
int				check_lex_errors(char *s);
int				check_only_spaces(char *s);
int				check_unclosed_quotes(char *s);
int				check_pipes(char *s);

// lex_utils.c
int				lex_error(char *token);
int				skip_spaces(char *s);
int				skip_quotes(char *s, char q);

// par_env_handler.c
char			*copy_var_value(char *env_var);
char			*get_variable_value(char **env, char *name);
char			*variable_not_found(void);
int				find_variable(char **envp, char *s, char **value);
char			*expander(char **envp, char *s);

// par_env_utils.c
int				check_ending(char *s, char *check);
char			*get_new_temp(char *temp, char *value, char *s);
void			copy_rest(char *s, char *temp, int *i, int *t);
char			*get_name(char *s, int i);
char			*exit_or_dollar(char c, int *i);

// par_free_more.c
void			free_token_list(t_token **token_list);
int				free_with_token_free(t_token **token_list);
int				free_token_and_struct(t_token **list, t_cmd_struct *cmd);

// par_free.c
int				free_in_handler(char *input);
int				return_with_strerror(int err);
char			*return_with_strerror_ptr(int err);
void			return_void(int err);
t_token			*return_with_strerror_tkn(int err);

// par_heredoc_utils.c
void			signal_heredoc_child(void);
void			quit_heredoc(int signal);
int				exit_heredoc(int pipe_fd);
void			signal_heredoc_parent(void);
int				heredoc_parent(pid_t pid, int *pipe_fd);

// par_interpret_list.c
int				interpreter(t_token **token_list, t_cmd_struct *cmd_struct);
t_token			*handle_sep(t_token **tkn_list, t_cmd_struct *cmd, int *n);
t_token			*handle_word(t_token **tkn_list, t_cmd_struct *cmd, int *n);
t_token			*handle_redirs(t_token **tkn_list, t_cmd_struct *cmd);
t_token			*interpret_loop(t_token **tknl, t_cmd_struct *cmd, int *n);

// par_only_redir_handler.c
int				redirector(t_token **token_list);
int				checker(t_token **token_list);
void			just_close(int *infile, int *outfile);

// par_parser.c
int				skip_from_end(char *s);
int				parser(t_cmd_struct *cmd_struct, char *s);
int				handle_input(t_cmd_struct *cmd_struct, char *input);
void			print_token_list(t_token **token_list);
void			struct_print(t_cmd_struct *cmd_struct);

// par_redir_handler.c
int				handle_in_redir(int *fd_infile, char *filename);
int				handle_out_redir(int *fd_outfile, char *filename);
int				handle_append(int *fd_outfile, char *filename);
int				handle_heredoc(int *fd_infile, char *deli);
void			heredoc_loop(int *pipe_fd, char *deli);

// par_token_init.c
t_token			*init_quotes(char *s, int *i, char q);
t_token			*init_pipe_or_sep(char *s, int *i, char p_or_s);
t_token			*init_single_red(char *s, int *i, char in_or_out);
t_token			*init_double_red(char *s, int *i, char in_or_out);
t_token			*init_word(char *s, int *i);

// par_token_list.c
t_token			*last_token(t_token *list);
void			token_add_back(t_token **list, t_token *new);
void			throw_away_quotes(char *s);
void			quotes_gone(char *s, char q, int *i, int *j);
void			tokenizer(char *s, t_token **token_list);
//------------END PARSING----------------//

// prompt.c
char			*prompt(void);

// init.c
int				get_array_size(char **envp);
char			**copy_env(char **envp, t_cmd_struct *cmd_struct);
char			**copy_env2(char **envp);

// run_commands.c
void			run_commands(t_cmd_struct *cmd_struct);

// redirect.c
void			redirect_parent(int *old_fds, int *new_fds,
					t_cmd_struct *cmd_struct);
void			redirect_child(int *old_fds, int *new_fds,
					t_cmd_struct *cmd_struct, int previous_command_exists);

// check_builtin.c
int				is_builtin(t_cmd_struct *cmd_struct);
int				check_builtin_1(t_cmd_struct *cmd_struct);
int				check_builtin_2(t_cmd_struct *cmd_struct);
void			try_env(t_cmd_struct *cmd_struct);
int				exit_helper(t_cmd_struct *cmd_struct);

//------------BUILTINS----------------//
// builtin_pwd.c
void			builtin_pwd(void);

// builtin_cd.c
void			builtin_cd(t_cmd_struct *cmd_struct);
char			*get_home_path(char **envp);

// builtin_echo.c
void			builtin_echo(t_cmd_struct *cmd_struct);

// builtin_export.c + helpers
void			builtin_export(t_cmd_struct *cmd_struct);
void			double_env_space(t_cmd_struct *cmd_struct);
char			*trim_quotes(char *string);
int				get_char_index(const char *s, int c);
char			**sort_env(char **env, t_cmd_struct *cmd_struct);
char			*put_quotes(char *str);
int				check_if_export_exists(char **env_var, char *export_var);
int				try_update_variables(t_cmd_struct *cmd_struct, int i, int j);
int				valid_input_helper(char *cur_cmd, int i);
int				check_valid_export_variable(char *cur_cmd);

// builtin_env.c
void			builtin_env(t_cmd_struct *cmd_struct);

// builtin_unset.c
void			builtin_unset(t_cmd_struct *cmd_struct);
int				valid_input_helper_unset(char *cur_cmd, int i);

// builtin_exit.c
void			builtin_exit(t_cmd_struct *cmd_struct);
//----------------END BUILTINS----------------//

// signals.c
void			signal_interactive(void);
void			signal_not_interactive(void);
void			interactive_sigint(int sign);
void			non_interactive_handler(int sign);
void			signal_child_active(void);

// helpers.c
char			**get_paths(char **envp, t_cmd_struct *cmd_struct);
void			update_env_copy(char ***env_copy, t_cmd_struct *cmd_struct);
void			set_command_path(char **envp, t_cmd_struct *cmd_struct);
char			*strjoin_free_first(char *str1, char *str2);

// helpers_2.c
char			*ft_strjoin_zero_allowed(char const *s1, char const *s2);
char			*strjoin_err(char const *s1, char const *s2);
char			*strjoin_no_free(char *result, char *temp);
char			*strjoin_free_second(char *str1, char *str2);
char			*strjoin_free_both(char *str1, char *str2);

// error.c
void			set_exit_status(char *string, int exit_int);
int				fork_failed(int pid);

// clean_up.c
void			clean_up(t_cmd_struct *cmd_struct);
void			loop_clean_up(t_cmd_struct *cmd_struct);
void			free_double_array(char **array);

#endif