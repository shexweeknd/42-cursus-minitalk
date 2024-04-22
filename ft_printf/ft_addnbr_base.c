/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:02:21 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/12 07:38:13 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recurse_nbr(char *buffer, int *index_ptr, long nbr, char *base)
{
	long	base_size;

	base_size = 0;
	while (base[base_size])
		base_size++;
	if (base_size == 0)
		return (0);
	if (nbr >= base_size)
	{
		recurse_nbr(buffer, index_ptr , nbr / base_size, base);
		ft_addchar_i(buffer, index_ptr, nbr % base_size + 48);
	}
	else if (nbr < base_size)
		ft_addchar_i(buffer, index_ptr, nbr % base_size + 48);
	return (*index_ptr);
}

static int	verify_errors(char *base)
{
	int	y;
	int	x;

	if (!base || !base[1])
		return (0);
	y = 0;
	while (base[y])
	{
		if (base[y] == '+' || base[y] == '-' || base[y] <= 32)
			return (0);
		y++;
	}
	x = 0;
	while (base[y])
	{
		x = y + 1;
		while (base[x])
		{
			if (base[x] == base[y])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_addnbr_base(char *buffer, int *index_ptr, long nbr, char *base)
{
	long n;
	int i;

	if (!verify_errors(base))
		return (0);
	n = nbr;
	i = 0;
	if (nbr < 0)
	{
		buffer[i++] = '-';
		n *= -1;
	}
	*index_ptr += recurse_nbr(buffer, &i, n, base);
	return ;
}