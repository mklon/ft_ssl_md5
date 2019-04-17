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

typedef enum	e_bool {
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_cipher {
	MD5,
	SHA256
}				t_cipher;

typedef struct	s_f {
	char		*name;
	char		*(*func)(char *);
}				t_f;

typedef struct	s_data {
	t_bool		q;
	t_bool		r;
	t_f			f;
}				t_data;

typedef struct	s_info {
	uint32_t	size;
	uchar_t		*base;
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
t_bool			get_f(char *str, t_f *f);
void			parse_input(int argc, char **argv);
char			*create_str(uint32_t *quad, int size);

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

void			algorithm_sha_2(uint32_t *t, uint32_t *res);
void			algorithm_sha_1(uint32_t *t, const uint32_t *x);
void			round_sha256(uint32_t *x, uint32_t *res);
char			*sha256(char *str);

/*
**	sha256_func.c
*/
uint32_t		r64(uint32_t x, uint32_t y);
uint32_t		s0(uint32_t x);
uint32_t		s1(uint32_t x);

/*
**	sha256_func2.c
*/

uint32_t		e0(uint32_t x);
uint32_t		e1(uint32_t x);
uint32_t		ma(uint32_t x, uint32_t y, uint32_t z);
uint32_t		ch(uint32_t x, uint32_t y, uint32_t z);

/*
**	input.c
*/

void			cipher_error(char *str);
char			*cat_str(char *ptr1, char *ptr2, int size, size_t num);
char			*read_str(int fd);
void			handle_p(t_data data, t_bool is_flag);
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
uint32_t		reverse(uint32_t i);
uint64_t		reverse_64(uint64_t i);
char			*to_16(uint32_t addr, int i, int j);

/*
**	print.c
*/

char			*get_up_chipher(char *str);
void			print_p(char *str, char *init, t_bool is_flag);
void			print_s(char *str, char *init, t_data data);
void			print_f(char *str, char *name, t_data data);

#endif
