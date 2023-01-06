# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 13:55:26 by hsliu             #+#    #+#              #
#    Updated: 2023/01/06 16:17:11 by hsliu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

MAKE	=	make

SRC_DIR	=	./src/

OBJ_DIR	=	./.obj/

INC_DIR	=	./include/

LIST_SRC	=	fractol.c ft_init.c \
				ft_draw.c draw_utils.c ft_is_which.c \
				hooks.c ft_mouse_hook.c

LIST_OBJ	=	$(LIST_SRC:.c=.o) 

LIST_INC	=	fractol.h

SRC		=	$(addprefix $(SRC_DIR), $(LIST_SRC))

OBJ		=	$(addprefix $(OBJ_DIR), $(LIST_OBJ))

INC		=	$(addprefix $(INC_DIR), $(LIST_INC))

LIB_DIR	=	libftprintf

LIB		=	libftprintf/libftprintf.a

MLX_DIR	=	mlx

MLX		=	libmlx.dylib

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -O3

all: $(NAME)

$(NAME)	:	$(OBJ_DIR) $(OBJ) $(INC) $(LIB) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Lmlx -lmlx -pthread -lm -framework OpenGL -framework AppKit $(LIB)

valgrind	:	$(OBJ_DIR) $(OBJ) $(INC) $(LIB) 
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ) -Lmlx -lmlx -pthread -lm -framework OpenGL -framework AppKit $(LIB)

$(MLX)	:	$(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)
	cp ./mlx/libmlx.dylib .

$(LIB): $(LIB_DIR)
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INC)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ -I $(INC_DIR) 

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

clean : 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: clean fclearn re all