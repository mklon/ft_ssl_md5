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

typedef enum	e_bool {
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_cipher {
	MD5,
	SHA256
}				t_cipher;

typedef struct	s_field {
	char		*text;
	t_cipher	cipher;
	t_bool		_p;
	t_bool		_q;
	t_bool		_r;
	t_bool		_s;
}				t_field;


/*
**	main.c
*/

int		main(int argc, char **argv);