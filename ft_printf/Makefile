NAME = libftprintf.a

SRC = ft_printf.c printf_utils.c

OBJS = $(SRC:.c=.o)

LIBFT_OBJS = libft/*.o

# BONUS_OBJS = 

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(OBJS)
	$(MAKE) -C libft
	ar -rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

$(NAME): all

# bonus: $(OBJS) $(BONUS_OBJS)
# 	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)
# add bonus here later

fclean:
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# include bonus here later