# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ivork <ivork@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/15 11:14:03 by ivork         #+#    #+#                  #
#    Updated: 2021/05/06 18:09:49 by ivork         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	minirt
SRCS			=	main.c\
					parse/parser.c\
					parse/resolution.c\
					parse/ambient.c\
					parse/camera.c\
					parse/light.c\
					parse/get_rgb.c\
					parse/get_coords.c\
					parse/parse_objects.c\
					parse/free.c\
					initialize/init_scene.c\
					initialize/init_camera.c
FLAGS			=	-Wall -Wextra -Werror
LIBFT			=	libft/libft.a
OBJ				=	$(SRCS:%.c=%.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@
$(LIBFT):
	make -C libft
clean:
	make fclean -C libft
	rm -f *.o
fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
re: fclean all