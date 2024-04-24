/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:57:26 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/21 13:05:14 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
		return (1024);
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
	res = ft_isalpha(argv[1][0]);
	if (res)
	{
		printf("%c est alpha\n", argv[1][0]);
		printf("%d", res);
	}
	else
	{
		printf("%c n'est pas alpha\n", argv[1][0]);
		printf("%d", res);
	}
	return (0);
}*/