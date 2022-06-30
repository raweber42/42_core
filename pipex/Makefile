NAME = pipex
LIBFT_DIR = libft/
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/ 
LIBFT_EXEC = libft.a

# place all source files here
SRC = 	$(SRC_DIR)main.c \
		$(SRC_DIR)error.c \
		$(SRC_DIR)helpers.c \
		$(SRC_DIR)run_command.c \
		$(SRC_DIR)init_linked_list.c \
		$(SRC_DIR)redirect.c \
		$(SRC_DIR)here_doc.c

# takes all named source files and converts them to .o files in the /obj directory
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# define compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -I $(INC_DIR)

# prevents rules from being considered as files
.PHONY: all clean fclean re

all: $(NAME)

# creates subdirectory /obj
$(OBJ_DIR):
	@mkdir $@

# makes sure to make a /obj dir before compiling .o files
$(OBJ): | $(OBJ_DIR)

# compiles .c files into .o files and puts them in the /obj folder
$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# compiles all object files and builds executable file 'pipex'
$(NAME): $(OBJ)
	$(MAKE) -C libft 
	$(CC) $(CFLAGS) $(LIBFT_DIR)$(LIBFT_EXEC) $^ -o $@
#	$(CC) $(CFLAGS) src/*.c PATH_TO_LIBFT/pipex/libft/libft.a -o pipex


# removes all object files and the /obj directory and cleans libft
clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ)
	rmdir $(OBJ_DIR)

# calls 'clean' and removes the executable
fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

# re-makes the whole compilation from scratch
re: fclean all
