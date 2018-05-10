# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 13:39:43 by osokoliu          #+#    #+#              #
#    Updated: 2018/05/05 13:26:04 by osokoliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = osokoliu.filler

FILE_C =  ft_read_write.c ft_parsing.c ft_filling_in_value.c

FILE_O = $(FILE_C:.c=.o)

GCC = gcc

FLAG = -Wall -Wextra -Werror

LIB_INC = -I libft/

LIBNAME = ./libft/libft.a

all: $(NAME)

$(LIBNAME): ./libft/libft.h
	make -C ./libft

$(NAME): $(LIBNAME) $(FILE_O)
	$(GCC) $(FILE_O) ./libft/libft.a -o $(NAME)

%.o: %.c
	$(GCC) $(FLAG) -c $< $(LIB_INC)

clean:
	make -C ./libft clean
	rm -f $(FILE_O)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
	make -C ./libft fclean