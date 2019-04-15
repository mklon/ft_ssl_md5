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

#ifndef FT_SSL_H
# define FT_SSL_H

# include "const.h"

# define BUFF 101
# define ADDR_SIZE 8
# define BASE_SIZE 64

# define F(x, y, z) ((x & y) | ((~x) & z))
# define G(x, y, z) ((x & z) | (y & (~z)))
# define H(x, y, z) (x ^ y ^ z)
# define I(x, y, z) (y ^ (x | (~z)))
# define R(v, s) (((v << s) | (v >> (32 - s))))

typedef enum	e_bool {
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_cipher {
	MD5,
	SHA256
}				t_cipher;

typedef struct	s_data {
	t_bool		q;
	t_bool		r;
	t_cipher	cipher;
}				t_data;

typedef struct	s_info {
	uint32_t	size;
	uchar_t		*base;
	char		*result;
}				t_info;

/*
**	main.c
*/

void			usage();
int				main(int argc, char **argv);

/*
**	parse.c
*/

void			parse_flags(int argc, char **argv, t_data data);
t_cipher		check_cipher(char *cipher);
void			parse_input(int argc, char **argv);
char			*create_str(uint32_t *quad);

/*
**	cipher.c
*/

char			*hash(char *str, t_cipher cipher);

/*
**	md5.c
*/

t_info			padding_md5(char *str);
uint32_t		*split(uchar_t *base);
char			*md5(char *str);

/*
**	input.c
*/

char			*cat_str(char *ptr1, char *ptr2, int size, size_t num);
char			*read_str(int fd);
void			handle_p(t_data data);
void			handle_s(char *str, t_data data);

/*
**	file.c
*/

void			handle_file(int argc, char **argv, int i, t_data data);

/*
**	helper.c
*/

void			error(char *msg);
char			*get_cipher(t_cipher cipher);
uint32_t		reverse(uint32_t i);
char			*to_16(uint32_t addr, int i, int j);

#endif
