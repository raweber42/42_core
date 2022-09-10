NAME = minishell
SRC_DIR = src/
BUILTIN_DIR = src/builtins/
PAR_DIR = src/parsing/
OBJ_DIR = obj/
INC_DIR = inc/
LIBFT_DIR = libft/
LIBFT_EXEC = libft.a
OS = $(shell uname)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -I $(HOME)/goinfre/.brew/opt/readline/include/
GREEN = \033[0;32m
RED = \033[0;31m
UNDO_COL = \033[0m
# FOR READLINE ON MAC:
# raweber@c2s9d36 ~/goinfre$ git clone https://github.com/Homebrew/brew.git .brew
# raweber@c2s9d36 ~/goinfre/.brew/bin$ ./brew install readline

# place all source files here
SRC = 	$(SRC_DIR)main.c \
		$(SRC_DIR)init.c \
		$(SRC_DIR)prompt.c \
		$(SRC_DIR)run_commands.c \
		$(SRC_DIR)redirect.c \
		$(SRC_DIR)error.c \
		$(SRC_DIR)helpers.c \
		$(SRC_DIR)helpers_2.c \
		$(SRC_DIR)check_builtin.c \
		$(BUILTIN_DIR)builtin_pwd.c \
		$(BUILTIN_DIR)builtin_cd.c \
		$(BUILTIN_DIR)builtin_export.c \
		$(BUILTIN_DIR)builtin_export_helpers.c \
		$(BUILTIN_DIR)builtin_export_helpers_2.c \
		$(BUILTIN_DIR)builtin_unset.c \
		$(BUILTIN_DIR)builtin_echo.c \
		$(BUILTIN_DIR)builtin_env.c \
		$(BUILTIN_DIR)builtin_exit.c \
		$(SRC_DIR)clean_up.c \
		$(SRC_DIR)signals.c \
		$(PAR_DIR)lex_check_redir.c \
		$(PAR_DIR)lex_check.c \
		$(PAR_DIR)lex_utils.c \
		$(PAR_DIR)par_env_handler.c \
		$(PAR_DIR)par_env_utils.c \
		$(PAR_DIR)par_free_more.c \
		$(PAR_DIR)par_free.c \
		$(PAR_DIR)par_heredoc_utils.c \
		$(PAR_DIR)par_interpret_list.c \
		$(PAR_DIR)par_interpret_utils.c \
		$(PAR_DIR)par_only_redir_handler.c \
		$(PAR_DIR)par_parser.c \
		$(PAR_DIR)par_redir_handler.c \
		$(PAR_DIR)par_token_init.c \
		$(PAR_DIR)par_token_list.c \

# takes all named source files and converts them to .o files in the /obj directory
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# prevents rules from being considered as files
.PHONY: all clean fclean re

all: $(NAME) credit

# creates subdirectory /obj
# makes sure to make a /obj dir before compiling .o files
$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# compiles all object files and builds executable file 'minishell' -> ADJUST READLINE FOR LINUX!
$(NAME): $(OBJ)
	@echo "$(RED)Compiling libft...$(UNDO_COL)"
	$(MAKE) -C libft
	@echo "$(RED)Compiling $(NAME)...$(UNDO_COL)"
	$(CC) $(CFLAGS) $^ $(LIBFT_DIR)$(LIBFT_EXEC) -L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline -o $@
	@echo "$(GREEN)SUCCESSFULLY CREATED MINISHELL!$(UNDO_COL)"

# removes all object files and the /obj directory and cleans libft
clean:
	$(MAKE) clean -C libft
	rm -r $(OBJ_DIR)
	@echo "$(RED)Finished clean$(UNDO_COL)"

# calls 'clean' and removes the executable
fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)
	@echo "$(RED)Finished fclean$(UNDO_COL)"

# re-makes the whole compilation from scratch
re: fclean all

credit:
	@echo "\n"
	@echo "███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
	@echo "████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
	@echo "██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
	@echo "         			  Made with love by: Alina and Ralf\n"
