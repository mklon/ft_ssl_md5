/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:57:42 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/12 20:57:43 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ssl.h"

void	cipher_error(char *str)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n"
			"Message Digest commands:\n"
			"md5\n"
			"sha256\n\n", str);
	usage();
}

char	*cat_str(char *ptr1, char *ptr2, int size, size_t num)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * size);
	if (res == NULL)
		error("malloc failed\n");
	if (ptr1 != NULL)
	{
		ft_strncpy(res, ptr1, (size_t)size);
		res[size - num] = '\0';
	}
	ft_strncat(res, ptr2, num);
	if (ptr1 != NULL)
		free(ptr1);
	return (res);
}

char	*read_str(int fd)
{
	int		num;
	int		size;
	char	*ptr;
	char	buffer[BUFF];

	size = 0;
	ptr = NULL;
	while ((num = (int)read(fd, buffer, BUFF - 1)) > 0)
	{
		size += num;
		buffer[num] = '\0';
		ptr = cat_str(ptr, buffer, size, (size_t)num);
	}
	return (ptr);
}

void	handle_p(t_data data, t_bool is_flag)
{
	char	*str;
	char	*res;

	str = read_str(0);
	if (str == NULL)
	{
		res = data.f.func("");
		print_p(res, str, is_flag);
	}
	else
	{
		res = data.f.func(str);
		print_p(res, str, is_flag);
		free(str);
	}
	free(res);
}

void	handle_s(char *str, t_data data)
{
	char	*res;

	res = data.f.func(str);
	print_s(res, str, data);
	free(res);
}
