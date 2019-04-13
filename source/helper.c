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

void	error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

char	*get_cipher(t_cipher cipher)
{
	if (cipher == MD5)
		return ("md5");
	else if (cipher == SHA256)
		return ("sha256");
	else
		return ("unknown cipher");
}
