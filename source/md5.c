/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 12:09:40 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/14 12:09:41 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ssl.h"

uint32_t	*split(uchar_t *base, t_bool rev)
{
	int			i;
	int			size;
	uint32_t	*x;

	i = -1;
	size = 0;
	x = (uint32_t *)malloc(sizeof(uint32_t) * 16);
	while (++i < 16)
	{
		ft_memcpy(&x[i], base + size, ADDR_SIZE / 2);
		if (rev == TRUE)
			x[i] = reverse(x[i]);
		size += ADDR_SIZE / 2;
	}
	return (x);
}

t_info	padding(char *str, t_bool res)
{
	int			i;
	t_info		info;
	uint64_t	size;

	i = -1;
	size = (uint32_t)ft_strlen(str);
	info.size = BASE_SIZE;
	while (info.size - ADDR_SIZE <= size)
		info.size += BASE_SIZE;
	info.base = (uchar_t *)malloc(info.size);
	ft_bzero(info.base, info.size);
	while (++i < size)
		info.base[i] = (uchar_t)str[i];
	if (res == TRUE)
		size = reverse_64(size * 8);
	else
		size *= ADDR_SIZE;
	info.base[i] = 0x80;
	ft_memcpy(&info.base[info.size - ADDR_SIZE], &size, ADDR_SIZE);
	return (info);
}

void	algorithm(int i, uint32_t *x, uint32_t *quad)
{
	uint32_t	res;
	uint32_t	temp;

	if (i < 16)
		res = F(quad[1], quad[2], quad[3]);
	else if (i < 32)
		res = G(quad[1], quad[2], quad[3]);
	else if (i < 48)
		res = H(quad[1], quad[2], quad[3]);
	else
		res = I(quad[1], quad[2], quad[3]);
	temp = quad[3];
	quad[3] = quad[2];
	quad[2] = quad[1];
	quad[1] += R((quad[0] + res + x[g_c[i]] + g_a_md5[i]), g_b[i]);
	quad[0] = temp;
}

void	round_md5(uint32_t *x, uint32_t *res)
{
	int			i;
	uint32_t	dop[4];

	i = -1;
	while (++i < 4)
		dop[i] = res[i];
	i = -1;
	while (++i < 64)
	{
		algorithm(i, x, res);
	}
	i = -1;
	while (++i < 4)
		res[i] += dop[i];
}

char	*md5(char *str)
{
	int			i;
	t_info		info;
	uint32_t	*x;
	uint32_t	res[4];

	i = -1;
	info = padding(str, FALSE);
	while (++i < 4)
		res[i] = g_d[i];
	i = 0;
	while (i < info.size)
	{
		x = split(&info.base[i], FALSE);
		round_md5(x, &res[0]);
		free(x);
		i += BASE_SIZE;
	}
	i = -1;
	while (++i < 4)
		res[i] = reverse(res[i]);
	return (create_str(&res[0]));
}
