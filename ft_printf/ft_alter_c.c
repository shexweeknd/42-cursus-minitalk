/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alter_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:27:49 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/12 07:46:51 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static void	ft_fullfill_c(t_data *data, int c)
{
	int	i;

	i = 0;
	if (data->format.width == 0)
		data->buffer[data->buffer_index] = (char)c;
	else if (data->format.minus)
	{
		data->buffer[data->buffer_index] = (char)c;
		while (--data->format.width)
			data->buffer[++data->buffer_index] = ' ';
	}
	else if (!data->format.minus)
	{
		data->buffer[data->format.width] = (char)c;
		while (--data->format.width)
			data->buffer[data->buffer_index++] = ' ';
	}
	return ;
}

void	ft_alter_c(t_data *data)
{
	//[-][width]
	ft_fullfill_c(data, va_arg(data->ap, char));
	data->buffer_index++;
	return ;
}