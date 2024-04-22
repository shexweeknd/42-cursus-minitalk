/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:49:26 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/21 13:05:17 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
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
	res = isascii(argv[1][0]);
	if (res)
	{
		printf("%c est ascii\n", argv[1][0]);
		printf("%d", res);
	}
	else
	{
		printf("%c n'est pas ascii\n", argv[1][0]);
		printf("%d", res);
	}
	return (0);
}*/