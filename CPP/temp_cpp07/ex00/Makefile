GREEN = \033[0;32m
RED = \033[0;31m
UNDO_COL = \033[0m

NAME = whatever
SRC_DIR = src/

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow
SRC =	main.cpp

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	@echo "$(RED)Compiling $(NAME)...$(UNDO_COL)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)SUCCESSFULLY CREATED $(NAME)!$(UNDO_COL)"

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all