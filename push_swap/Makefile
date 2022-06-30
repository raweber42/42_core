NAME = push_swap

SRC_DIR = src/
OBJ_DIR = obj/
BONUS_DIR = bonus/
INC_DIR = inc/
LIBFT_DIR = libft/
LIBFT_EXEC = libft.a

# place all source files here
SRC = 	$(SRC_DIR)main.c \
		$(SRC_DIR)list_helpers.c \
		$(SRC_DIR)ps_options_1.c \
		$(SRC_DIR)ps_options_2.c \
		$(SRC_DIR)ps_options_3.c \
		$(SRC_DIR)check_stack.c \
		$(SRC_DIR)ps_error.c \
		$(SRC_DIR)ps_atol.c \
		$(SRC_DIR)init_stack.c \
		$(SRC_DIR)radix_sort.c \
		$(SRC_DIR)small_stack_sort_1.c \
		$(SRC_DIR)small_stack_sort_2.c

BONUS = $(BONUS_DIR)create_checker.c \
		$(SRC_DIR)list_helpers.c \
		$(SRC_DIR)ps_options_1.c \
		$(SRC_DIR)ps_options_2.c \
		$(SRC_DIR)ps_options_3.c \
		$(SRC_DIR)check_stack.c \
		$(SRC_DIR)ps_error.c \
		$(SRC_DIR)ps_atol.c \
		$(SRC_DIR)init_stack.c


# takes all named source files and converts them to .o files in the /obj directory
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# define compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -I $(INC_DIR)

# prevents rules from being considered as files
.PHONY: all clean fclean re bonus

all: $(NAME)

# creates subdirectory /obj
$(OBJ_DIR):
	@mkdir $@

# makes sure to make a /obj dir before compiling .o files
$(OBJ): | $(OBJ_DIR)

# compiles .c files into .o files and puts them in the /obj folder
$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# compiles all object files and builds executable file 'push_swap'
$(NAME): $(OBJ)
	$(MAKE) -C libft 
	$(CC) $(CFLAGS) $(LIBFT_DIR)$(LIBFT_EXEC) $^ -o $@

bonus: $(BONUS)
	$(CC) $(CFLAGS) $(LIBFT_DIR)$(LIBFT_EXEC) -L./ $^ -o checker

# removes all object files and the /obj directory and cleans libft
clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ)
	rmdir $(OBJ_DIR)

# calls 'clean' and removes the executable
fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)
	rm -f checker

# re-makes the whole compilation from scratch
re: fclean all

# tests for memory leaks with valgrind
valgrind: all
	valgrind --leak-check=full -s ./$(NAME) 1 2 3 4 5

# tests for memory leaks with mac 'leaks' command
leaks: all
	leaks --atExit -- ./$(NAME) 1 2 3 4 5

# ADD INCLUDE DIR IF NEEDED (OTHER LIBRARIES)