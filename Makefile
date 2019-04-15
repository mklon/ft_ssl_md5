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

NAME = ft_ssl

CC = gcc

LIBFT = printflibft/libftprintf.a

SRC =	source/md5.c\
        source/main.c\
		source/file.c\
		source/parse.c\
		source/input.c\
		source/helper.c\
		source/cipher.c\
		source/sha256.c\

OBJ = $(SRC:.c=.o)

HEADERS =	headers/const.h\
			headers/ft_ssl.h\
			printflibft/ft_printf.h\
			printflibft/get_next_line.h\

FLAGS = -Wall -Wextra -Werror

all: $(NAME) done

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): %.o: %.c
	$(CC) -c  $< -o $@

$(LIBFT):
	make -C printflibft/
	@echo "\033[;35m[ Libft is ready ]\033[33;0m"

libft_clean:
	make -C printflibft/ clean

libft_fclean:
	make -C printflibft/ fclean

clean: libft_clean
	rm -f $(OBJ) lem_in.h.gch get_next_line.h.gch *~
	@echo "\033[;33m[ It's clean ]\033[33;0m"

fclean: clean libft_fclean
	@rm -f $(NAME)
	@echo "\033[;31m[ Deleted ]\033[33;0m"

re: fclean all

done:
	@echo "\033[;32m[ Well done ]\033[33;0m"
