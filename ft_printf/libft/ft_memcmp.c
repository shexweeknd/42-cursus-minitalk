/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:14:09 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/23 14:12:19 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	source_ln;

	source_ln = 0;
	while (*(unsigned char *)(s1 + source_ln))
		source_ln++;
	while (n--)
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (1);
		else if (*(unsigned char *)s1++ < *(unsigned char *)s2++)
			return (-1);
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s1 = "";
	char *s2 = "test";
	int ret;
	int n = 4;

	ret = ft_memcmp(s1, s2, n);
	printf("%d\n", ret);
	return (0);
}*/