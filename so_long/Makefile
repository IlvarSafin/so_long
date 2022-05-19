NAME    =   so_long
SRCS    =   check.c enemy_walk.c ft_itoa.c ftmap.c\
			get_next_line.c get_next_line_utils.c\
			initialization.c key_hook.c move.c out.c\
			so_long.c utils.c\
 
INCLUDE = so_long.h
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -framework OpenGL -framework AppKit -lmlx
all : $(NAME)
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -I./include $(MLX) libmlx.dylib -o $(NAME)
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
.PHONY: clean fclean re all