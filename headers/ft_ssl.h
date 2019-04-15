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
# define R(x, y) (((x << y) | (x >> (32 - y))))

# define R64(x, y)	(((x >> y) | (x << (32 - y))))
# define MA(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
# define S0(x)	(R64(x, 7) ^ R64(x, 18) ^ (x >> 3))
# define S1(x)	(R64(x, 17) ^ R64(x, 19) ^ (x >> 10))
# define E0(x)	(R64(x, 2) ^ R64(x, 13) ^ R64(x, 22))
# define E1(x)	(R64(x, 6) ^ R64(x, 11) ^ R64(x, 25))
# define CH(x, y, z) ((x & y) ^ ((~x) & z))


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

t_info			padding(char *str, t_bool res);
uint32_t		*split(uchar_t *base, t_bool rev);
void			algorithm(int i, uint32_t *x, uint32_t *quad);
void			round_md5(uint32_t *x, uint32_t *res);
char			*md5(char *str);

/*
**	sha256.c
*/

void			round_sha256(uint32_t *x, uint32_t *res);
char			*sha256(char *str);

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

char			*read_file(char *name);
void			error_file(char *name, t_data data);
void			handle_file(int argc, char **argv, int i, t_data data);

/*
**	helper.c
*/

void			error(char *msg);
char			*get_cipher(t_cipher cipher);
uint32_t		reverse(uint32_t i);
uint64_t		reverse_64(uint64_t i);
char			*to_16(uint32_t addr, int i, int j);

#endif
