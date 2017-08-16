NAME = rtv1

SRC = main.c rt_sphere1.c ft_init.c

OBJ = $(SRC:.c=.o)

HEAD = rtv.h

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc -o $(NAME) -O3 -lmlx -framework OpenGL -framework AppKit -lpthread $(OBJ) libft/*.o

%.o: %.c
	@gcc $(FLAGS) -c -o  $@ $<

cleanlib:
	@make clean -C libft/

fcleanlib:
	@make fclean -C libft/

clean: cleanlib
	@rm -f $(OBJ)

fclean:	clean fcleanlib
	@rm -f $(NAME)

re: fclean all
