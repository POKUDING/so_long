# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 13:45:28 by junhyupa          #+#    #+#              #
#    Updated: 2023/01/23 22:39:59 by junhyupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := CC
CFLAGS := -Wall -Werror -Wextra -g -fsanitize=address
COPT := -framework OpenGL -framework Appkit

SRC := so_long.c checker.c path_finder.c map_maker.c util.c data_control.c graphic.c
SRCS := $(addprefix ./srcs/,$(SRC))

OBJS := $(SRCS:.c=.o)

MLX := -L./ -lmlx
INCLUDE := so_long.h $(MLX)

LIBFT := ./libft/libft.a
LIBFT_DIR := ./libft/

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I $(INCLUDE) -o $(NAME)

$(LIBFT) :
	make -C $(LIBFT_DIR)

.PHONY : all clean fclean re
