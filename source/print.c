/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:55:15 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/16 21:55:15 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ssl.h"

char	*get_up_chipher(t_cipher cipher)
{
	if (cipher == MD5)
		return ("MD5");
	else if (cipher == SHA256)
		return ("SHA256");
	else
		return ("unknown cipher");
}

void	print_p(char *str, char *init)
{
	ft_printf("%s%s\n", init, str);
}

void	print_s(char *str, char *init, t_data data)
{
	char	*cipher;

	cipher = get_up_chipher(data.cipher);
	if (data.q == TRUE)
	{
		ft_printf("%s\n", str);
		return ;
	}
	if (data.r == TRUE)
	{
		ft_printf("%s \"%s\"\n", str, init);
		return ;
	}
	ft_printf("%s (\"%s\") = %s\n", cipher, init, str);
}

void	print_f(char *str, char *name, t_data data)
{
	char	*cipher;

	cipher = get_up_chipher(data.cipher);
	if (data.q == TRUE)
	{
		ft_printf("%s\n", str);
		return ;
	}
	if (data.r == TRUE)
	{
		ft_printf("%s %s\n", str, name);
		return ;
	}
	ft_printf("%s (%s) = %s\n", cipher, name, str);
}
