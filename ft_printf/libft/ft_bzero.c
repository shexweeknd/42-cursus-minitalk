/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:46:44 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/22 13:42:52 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n--)
		*(unsigned char *)(s + i++) = 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int	main(void)
{
	int nbr;
	int i;
	int counter;
	char *buffer;

	counter = 12;
	buffer = (char *)malloc(sizeof(int )* counter);

	i = 0;
	while (i < counter)
		buffer[i++] = 1;

	i = 0;
	while (i < counter)
	{
		printf("%d", buffer[i++]);
	}
	printf("\n");

	nbr = 4;
	bzero(buffer, nbr);

	i = 0;
	while (i < counter)
	{
		printf("%d", buffer[i++]);
	}
	printf("\n");

	free(buffer);
	return (0);
}*/