/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:09:30 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/12 08:28:22 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

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
		recurse_nbr(buffer, index_ptr, nbr / base_size, base);
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

void	ft_addx(char *buffer, int *index_ptr, unsigned int nbr, char *base)
{
	int	i;

	i = 0;
	if (!verify_errors(base))
		return (0);
	*index_ptr += recurse_nbr(buffer, &i, nbr, base);
	return ;
}
