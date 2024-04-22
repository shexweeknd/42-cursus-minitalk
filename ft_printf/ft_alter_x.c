/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alter_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:05:12 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/12 08:22:18 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static void	ft_fullfill_x(t_data *data, unsigned int nbr)
{
	return ;
}

void	ft_alter_x(t_data *data)
{
	//[-0#][width][precision]
	ft_fullfill_x(data, va_arg(data->ap, unsigned int));
	return ;
}

/*
    0 ne fonctionne pas avec precision
    0 ne fonctionne pas avec '-'
    # ajoute 0x devant la valeur hexa
*/

/*
    priorite:
    # >

*/