# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JUN <JUN@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 13:45:28 by junhyupa          #+#    #+#              #
#    Updated: 2023/02/09 17:09:01 by JUN              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := cc
CFLAGS := -Wall -Werror -Wextra -g -fsanitize=address
COPT := -framework OpenGL -framework Appkit

SRC := so_long.c \
		checker.c \
		path_finder.c \
		map_maker.c \
		util.c \
		data_control.c \
		graphic.c \
		move.c \
		img_init.c \
		game.c
SRCS := $(addprefix ./mandatory_srcs/,$(SRC))

BNS_SRC := so_long_bonus.c \
			checker_bonus.c \
			path_finder_bonus.c \
			map_maker_bonus.c \
			util_bonus.c \
			data_control_bonus.c \
			graphic_bonus.c \
			move_bonus.c \
			img_init_bonus.c \
			game_bonus.c \
			bonus_bonus.c
BNS_SRCS := $(addprefix ./bonus_srcs/,$(BNS_SRC))

OBJS := $(SRCS:.c=.o)
BNS_OBJS := $(BNS_SRCS:.c=.o)

MLX := -Lmlx -lmlx


LIBFT := ./libft/libft.a
LIBFT_DIR := ./libft/

INCLUDE := so_long.h $(MLX)
BNS_INCLUDE := so_long_bonus.h $(MLX)


ifdef BONUS
	OBJS = $(BNS_OBJS)
	INCLUDE = $(BNS_INCLUDE)
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(BNS_OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -I $(INCLUDE) -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

bonus :
	make BONUS=1

.PHONY : all clean fclean re
