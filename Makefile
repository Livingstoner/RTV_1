#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 02:03:27 by rkhokhlo          #+#    #+#              #
#    Updated: 2019/03/28 02:03:29 by rkhokhlo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = rtv1
SOURCE =		main.c \
				keyboard.c \
				colors.c \
				list.c \
				parser.c \
				parse_object.c \
				parse_founctions.c \
				init_window.c \
				vector.c \
				simple_functions.c \
				raytracer.c \
				intersections.c \
				find_normal.c \
				light.c	\
				find_functions.c \
				valid.c
LIBFT = libft/libft.a
MINILIBX = -L/usr/local/include -lmlx -framework OpenGL -framework AppKit -lpthread
OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR),  $(SOURCE:.c=.o))

FLAG = -Wall -Wextra -Werror -I libft

all: $(NAME)

$(OBJ): $(OBJDIR)%.o: %.c
	gcc -c -g $(FLAG) $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	gcc -g $(OBJ) $(LIBFT) $(MINILIBX) -o $(NAME) 

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
