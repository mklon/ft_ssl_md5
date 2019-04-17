/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:15:34 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/12 19:15:34 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ssl.h"

void	parse_flags(int argc, char **argv, t_data data)
{
	int		i;

	i = 1;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-q"))
			data.q = TRUE;
		else if (!ft_strcmp(argv[i], "-r"))
			data.r = TRUE;
		else if (!ft_strcmp(argv[i], "-p"))
			handle_p(data, TRUE);
		else if (!ft_strcmp(argv[i], "-s"))
		{
			if (++i < argc)
				handle_s(argv[i], data);
		}
		else
		{
			handle_file(argc, argv, i - 1, data);
			return ;
		}
	}
}

t_bool	get_f(char *str, t_f *f)
{
	int		i;
	t_f		fu[2];

	i = -1;
	fu[0].name = "md5";
	fu[0].func = &md5;
	fu[1].name = "sha256";
	fu[1].func = &sha256;
	while (++i < N)
	{
		if (!ft_strcmp(str, fu[i].name))
		{
			f->func = fu[i].func;
			f->name = fu[i].name;
			return (TRUE);
		}
	}
	return (FALSE);
}

void	parse_input(int argc, char **argv)
{
	t_data	data;
	t_f		f;

	data.q = FALSE;
	data.r = FALSE;
	if ((get_f(argv[1], &f)) == FALSE)
		cipher_error(argv[1]);
	data.f = f;
	if (argc == 2)
		handle_p(data, FALSE);
	else
		parse_flags(argc, argv, data);
}

char	*create_str(uint32_t *quad, int size)
{
	int		i;
	char	*str;
	char	*hex;
	char	*res;

	res = NULL;
	str = (char *)malloc(sizeof(char) * 64);
	ft_bzero(str, 64);
	i = -1;
	while (++i < size)
	{
		hex = to_16(quad[i], 0, 0);
		hex[8] = '\0';
		res = ft_strjoin(str, hex);
		free(hex);
		free(str);
		str = res;
	}
	return (res);
}
