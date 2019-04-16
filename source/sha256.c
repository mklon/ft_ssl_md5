/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:33:03 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/15 21:33:04 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ssl.h"

void	algorithm_sha_2(uint32_t *t, uint32_t *res)
{
	int			i;
	uint32_t	t1;
	uint32_t	t2;

	i = -1;
	while (++i < 64)
	{
		t1 = res[7] + e1(res[4]) + ch(res[4], res[5], res[6]) + g_s[i] + t[i];
		t2 = e0(res[0]) + ma(res[0], res[1], res[2]);
		res[7] = res[6];
		res[6] = res[5];
		res[5] = res[4];
		res[4] = res[3] + t1;
		res[3] = res[2];
		res[2] = res[1];
		res[1] = res[0];
		res[0] = t1 + t2;
	}
}

void	algorithm_sha_1(uint32_t *t, const uint32_t *x)
{
	int		i;

	i = -1;
	while (++i < 64)
		if (i < 16)
			t[i] = x[i];
		else
			t[i] = t[i - 16] + s0(t[i - 15]) + t[i - 7] + s1(t[i - 2]);
}

void	round_sha256(uint32_t *x, uint32_t *res)
{
	int			i;
	uint32_t	t[64];
	uint32_t	dop[8];

	i = -1;
	while (++i < 8)
		dop[i] = res[i];
	algorithm_sha_1(t, x);
	algorithm_sha_2(t, res);
	i = -1;
	while (++i < 8)
		res[i] += dop[i];
}

char	*sha256(char *str)
{
	int			i;
	t_info		info;
	uint32_t	*x;
	uint32_t	res[8];

	i = -1;
	info = padding(str, TRUE);
	while (++i < 8)
		res[i] = g_d_sha[i];
	i = 0;
	while (i < info.size)
	{
		x = split(&info.base[i], TRUE);
		round_sha256(x, &res[0]);
		free(x);
		i += BASE_SIZE;
	}
	return (create_str(res, 8));
}
