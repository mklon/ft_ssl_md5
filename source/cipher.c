/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 11:53:10 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/14 11:53:10 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ssl.h"

char	*hash(char *str, t_cipher cipher)
{
	if (cipher == MD5)
		return (md5(str));
	else if(cipher == SHA256)
		return (sha256(str));
	else
		error("unknown cipher\n");
	return (NULL);
}
