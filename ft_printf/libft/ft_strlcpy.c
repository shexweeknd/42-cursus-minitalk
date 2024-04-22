/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:11:26 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/27 11:41:42 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	if (size < 1)
		return (count);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

/*
#include <stdio.h>
#include <strings.h>

int	main(void)
{
	char src[] = "Nuts Channel Is Back";
	char dst[] = "I am the only one";

	printf("%s\n", dst);
	ft_strlcpy(dst, src, 5);
	printf("%s\n", dst);
	return (0);
}*/