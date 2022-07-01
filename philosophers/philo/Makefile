NAME = philo
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/ 

# place all source files here
SRC = 	$(SRC_DIR)main.c \
		$(SRC_DIR)atoi.c \
		$(SRC_DIR)utils.c \
		$(SRC_DIR)init.c \
		$(SRC_DIR)clean_up.c \

# takes all named source files and converts them to .o files in the /obj directory
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# define compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

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

# compiles all object files and builds executable file 'philo'
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -pthread $^ -o $@

# removes all object files and the /obj directory and cleans libft
clean:
	rm -f $(OBJ)
	rmdir $(OBJ_DIR)

# calls 'clean' and removes the executable
fclean: clean
	rm -f $(NAME)

# re-makes the whole compilation from scratch
re: fclean all
