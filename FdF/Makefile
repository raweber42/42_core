NAME = fdf

SRCS =  read_file.c main.c draw.c my_put_pixel.c events.c handle_colors.c \
		isometric.c allocate.c error.c destroy.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MINILIBX_MAC = minilibx_macos/libmlx.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

# $@ is an automatic variable that evaluates to the target of the rule (something.o), 
# and $< is an automatic variable which evaluates to the first prerequisite (something.c) of the rule. 
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): all

all: $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C minilibx_macos
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX_MAC) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

valgrind:
	valgrind --leak-check=full -s ./$(NAME) test_maps/42.fdf

leaks:
	leaks --atExit -- ./$(NAME) test_maps/42.fdf

.PHONY: all clean fclean re valgrind leaks

#LINUX
#MINILIBX_LINUX = minilibx-linux/libmlx.a

# all: $(OBJS)
# 	$(MAKE) -C libft
# 	$(MAKE) -C minilibx-linux
# 	$(CC) $(OBJS) -L/usr/lib minilibx-linux/libmlx.a libft/libft.a -lXext -lX11 -lm -lz -o $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux -c $< -o $@
