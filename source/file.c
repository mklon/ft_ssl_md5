/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:58:31 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/13 11:58:31 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ssl.h"

void	error_file(char *name, t_data data)
{
	ft_printf("ft_ssl: %s: %s: No such file or directory\n",
			get_cipher(data.cipher), name);
}

char	*read_file(char *name)
{
	int		fd;
	char	*str;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (NULL);

	str = read_str(fd);

	return (str);
}

void	handle_file(int argc, char **argv, int i, t_data data)
{
	char	*str;

	while (++i < argc)
	{
		str = read_file(argv[i]);
		if (str == NULL)
		{
			error_file(argv[i], data);
			continue ;
		}
 		hash(str, data.cipher);

		//DISPLAY
		free(str);
	}
}
