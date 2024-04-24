/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:54:29 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/21 13:05:24 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int res;

	if (argc != 2)
	{
		printf("Veuiller ajouter un argument\n");
		return (1);
	}
	res = ft_isprint(argv[1][0]);
	if (res)
	{
		printf("%c est printable \n", argv[1][0]);
		printf("%d", res);
	}
	else
	{
		printf("%c n'est pas printable\n", argv[1][0]);
		printf("%d", res);
	}
	return (0);
}*/