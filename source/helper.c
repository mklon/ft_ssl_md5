/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:27:56 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/12 19:27:57 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ssl.h"

void		error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

char		*get_cipher(t_cipher cipher)
{
	if (cipher == MD5)
		return ("md5");
	else if (cipher == SHA256)
		return ("sha256");
	else
		return ("unknown cipher");
}

uint32_t	reverse(uint32_t i)
{
	uint32_t	res;

	res = ((i << 8) & 0xFF00FF00) | ((i >> 8) & 0xFF00FF);
	return ((res << 16) | (res >> 16));
}

uint64_t	reverse_64(uint64_t i)
{
	uint64_t	res;

	res = ((i << 8) & 0xFF00FF00FF00FF00ULL)
			| ((i >> 8) & 0x00FF00FF00FF00FFULL);
	res = ((res << 16) & 0xFFFF0000FFFF0000ULL)
			| ((res >> 16) & 0x0000FFFF0000FFFFULL);
	return (res << 32) | (res >> 32);
}

char		*to_16(uint32_t addr, int i, int j)
{
	int		hex;
	char	buff[16];
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * 16);
	ft_bzero(buff, 16);
	while (addr != 0)
	{
		hex = addr % 16;
		if (hex >= 10)
			buff[i++] = (char)(hex + 'a' - 10);
		else
			buff[i++] = (char)(hex + '0');
		addr /= 16;
	}
	while (i < 8)
	{
		buff[i] = '0';
		buff[i++ + 1] = '\0';
	}
	i--;
	while (i >= 0)
		res[j++] = buff[i--];
	return (res);
}
