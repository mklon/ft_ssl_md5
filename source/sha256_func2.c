/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:50:38 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/16 20:50:38 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ssl.h"

uint32_t	e0(uint32_t x)
{
	return (r64(x, 2) ^ r64(x, 13) ^ r64(x, 22));
}

uint32_t	e1(uint32_t x)
{
	return (r64(x, 6) ^ r64(x, 11) ^ r64(x, 25));
}

uint32_t	ma(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

uint32_t	ch(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (~x & z));
}
