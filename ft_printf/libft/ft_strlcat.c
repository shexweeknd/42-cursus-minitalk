/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:57:02 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/27 11:55:17 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	i = 0;
	j = d_len;
	if (size == 0)
		return (s_len);
	while (src[i] && (j < size - 1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (size <= d_len)
		return (s_len + size);
	return (d_len + s_len);
}
/*
#include "libft.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	unsigned int res;
	char *dest;

	dest = (char *)malloc(sizeof(*dest) * 15);
	memset(dest, 'r', 15);
	res = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
	printf("%u\n%s\n", res, dest);
	free(dest);
	return (0);
}*/
