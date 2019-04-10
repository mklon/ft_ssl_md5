#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 18:55:35 by oposhiva          #+#    #+#              #
#    Updated: 2019/04/10 18:55:35 by oposhiva         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_sslo

CC = gcc

LIBFT = printflibft/libftprintf.a

SRC = src/main.c

OBJ = $(SRC:.c=.o)

HEADERS = lem_in.h printflibft/get_next_line.h printflibft/ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C printflibft/

libft_clean:
	make -C printflibft/ clean

libft_fclean:
	make -C printflibft/ fclean

clean: libft_clean
	rm -f $(OBJ) lem_in.h.gch get_next_line.h.gch *~

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all