/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:44:27 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/11 18:44:31 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ssl.h"

void	usage(void)
{
	ft_printf("usage: ./ft_ssl [md5 | sha256] [-p | -q | -r ]"
				"[-s string] [files...]\n");
	ft_printf("\n\t-p, echo STDIN to STDOUT and append the checksum to STDOUT\n"
				"\t-q, quiet mode\n"
				"\t-r, reverse the format of the output.\n"
				"\t-s, print the sum of the given string\n\n");
	exit(1);
}

int		main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	if (argc == 1)
		usage();
	parse_input(argc, argv);
	return (0);
}
