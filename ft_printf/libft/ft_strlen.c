/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:00:39 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/22 13:54:15 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
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
	res = ft_strlen(argv[1]);
	if (res)
		printf("%s est de taille : %d\n", argv[1], res);
	return (0);
}*/