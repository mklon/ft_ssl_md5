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
	int 	i;

	i = 1;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-q"))
			data._q = TRUE;
		else if (!ft_strcmp(argv[i], "-r"))
			data._r = TRUE;
		else if (!ft_strcmp(argv[i], "-p"))
			handle_p(data);
		else if (!ft_strcmp(argv[i], "-s"))
		{
			if (++i < argc)
				handle_s(argv[i]);
		}
		else
		{
			handle_file(argc, argv, i - 1, data);
			return ;
		}
	}
}

t_cipher	check_cipher(char *cipher)
{
	t_cipher	result;


	result = 2;
	if (!ft_strcmp(cipher, "md5") || !ft_strcmp(cipher, "MD5"))
		result = MD5;
	else if (!ft_strcmp(cipher, "sha256") || !ft_strcmp(cipher, "SHA256"))
		result = SHA256;
	else
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", cipher);
		usage();
		error("");
	}
	return (result);
}

void	parse_input(int argc, char **argv)
{
	int		i;
	t_data	data;

	i = 2;
	data._q = FALSE;
	data._r = FALSE;
	data.cipher = check_cipher(argv[1]);
	parse_flags(argc, argv, data);
}
