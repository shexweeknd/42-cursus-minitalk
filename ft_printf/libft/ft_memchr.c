/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:06:10 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/22 13:45:33 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t b_size)
{
	char	*ret;

	ret = 0;
	while (b_size--)
	{
		if (*(unsigned char *)str == (unsigned char)c)
		{
			ret = (char *)str++;
			break ;
		}
		else
			str++;
	}
	return (ret);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s = "bonjour je fais parti de l'elite";
	char *ret;
	char c = 'e';
	int n = 9;

	ret = memchr(s, c, n);
	printf("%s\n", ret);
	return (0);
}*/