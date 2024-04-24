/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:03:18 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/23 14:12:39 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if ((char)c == '\0')
	{
		while (*str++)
			;
		return ((char *)(--str));
	}
	while (*str)
		if (*str++ == (char)c)
			return ((char *)(--str));
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*ret;
	char	*str;

	str = "teste";
	ret = ft_strchr(str, 1024);
	printf("%s", ret);
	return (0);
}*/
