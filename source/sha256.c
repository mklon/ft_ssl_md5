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

void	algorithm_sha_2()
{
	int		i;

	i = -1;
	while (++i < 64)
	{

	}

}

void	algorithm_sha_1(uint32_t *t, uint32_t *x)
{
	int		i;

	i = -1;
	while (++i < 64)
		if (i < 64)
			t[i] = x[i];
		else
			t[i] = t[i - 16] + S0(x[i - 15]) + t[i - 7] + S1(x[i - 2]);
}

void	round_sha256(uint32_t *x, uint32_t *res)
{
	int			i;
	uint32_t	dop[8];
	uint32_t	t[64];

	i = -1;
	while (++i < 8)
		dop[i] = res[i];
	algorithm_sha_1(t, x);
	algorithm_sha_2();
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

}