/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:10:00 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/21 13:05:08 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)) || ((c >= 48)
			&& (c <= 57)))
		return (8);
	return (0);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	int res;

	if (argc != 2)
	{
		printf("Veuiller ajouter un argument\n");
		return (1);
	}
	res = ft_isalnum(argv[1][0]);
	if (res)
	{
		printf("%c est alphanum\n", argv[1][0]);
		printf("%d", res);
	}
	else
	{
		printf("%c n'est pas alphanum\n", argv[1][0]);
		printf("%d", res);
	}
	return (0);
}*/