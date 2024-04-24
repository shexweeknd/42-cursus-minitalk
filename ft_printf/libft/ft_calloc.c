/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:45:44 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/27 11:58:04 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char		*ret;
	long long	total;

	total = n * size;
	if (total < 0 || (n >= SIZE_MAX && size >= SIZE_MAX) || (size
			&& n > (UINT_MAX / size)))
		return (NULL);
	ret = (void *)malloc(total);
	if (!ret)
		return (NULL);
	if (ret)
	{
		ft_bzero(ret, total);
		return (ret);
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char	*res;

	//res = ft_calloc(2, 2);
	res = ft_calloc(-5, -5);
	//res = ft_calloc(SIZE_MAX, SIZE_MAX);
	free(res);
	return (0);
}
*/
