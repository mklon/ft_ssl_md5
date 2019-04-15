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
			data.q = TRUE;
		else if (!ft_strcmp(argv[i], "-r"))
			data.r = TRUE;
		else if (!ft_strcmp(argv[i], "-p"))
			handle_p(data);
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
	t_data	data;

	data.q = FALSE;
	data.r = FALSE;
	data.cipher = check_cipher(argv[1]);
	parse_flags(argc, argv, data);
}

char	*create_str(uint32_t *quad)
{
	int		i;
	char	*str;
	char	*hex;
	char	*res;

	res = NULL;
	str = (char *)malloc(sizeof(char) * 64);
	ft_bzero(str, 64);
	i = -1;
	while (++i < 4)
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