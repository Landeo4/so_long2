# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 10:25:01 by tpotilli@st       #+#    #+#              #
#    Updated: 2023/10/23 14:23:41 by tpotilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	srcs/main.c\
		utils/gnl_utils.c\
		utils/gnl.c\
		utils/ft_putchar.c\
		utils/ft_putnbr_base.c\
		utils/ft_putnbr.c\
		utils/ft_putstr.c\
		utils/ft_printf.c\
		utils/ft_putnbr_void.c\
		utils/ft_itoa.c\
		utils/perror.c\
		utils/ft_strlen.c\
		parsing/verif_map.c\
		parsing/parsing.c\

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INC_PATH = ./include

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_PATH) -Imlx_linux -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re