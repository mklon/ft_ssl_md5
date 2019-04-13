/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:55:16 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/10 18:55:16 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include "../printflibft/get_next_line.h"
# include "../printflibft/ft_printf.h"
# include "../printflibft/libft/libft.h"

# define BUFF 101

typedef enum	e_bool {
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_cipher {
	MD5,
	SHA256
}				t_cipher;

typedef struct	s_data {
	t_bool		_q;
	t_bool		_r;
	t_cipher	cipher;
}				t_data;


/*
**	main.c
*/

void		usage();
int			main(int argc, char **argv);

/*
**	parse.c
*/

void		parse_flags(int argc, char **argv, t_data data);
t_cipher	check_cipher(char *cipher);
void		parse_input(int argc, char **argv);

/*
**	input.c
*/

char		*cat_str(char *ptr1, char *ptr2, int size, size_t num);
char		*read_str(int fd);
void		handle_p(t_data data);
void		handle_s(char *str);

/*
**	file.c
*/

void		handle_file(int argc, char **argv, int i, t_data data);

/*
**	helper.c
*/

void		error(char *msg);
char		*get_cipher(t_cipher cipher);
