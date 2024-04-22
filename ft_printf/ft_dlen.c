/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:23:38 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/12 07:32:10 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

size_t	ft_ullen(unsigned long nbr)
{
	size_t	res;

	res = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		res++;
	}
	return (res);
}

long	ft_abs(int nbr)
{
	if (nbr == -2147483648)
		return (2147483648);
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

size_t ft_intlen(int nbr)
{
	size_t size;

	size = 1;
	if (nbr < 0)
		size++;
	size += ft_ullen (ft_abs(nbr));
}