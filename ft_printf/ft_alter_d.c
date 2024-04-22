/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alter_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 03:57:41 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/12 07:34:04 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static void	ft_alter_data(t_data *data, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		data->buffer[data->buffer_index++] = buffer[i++];
	free(buffer);
	return ;
}

static void	ft_add_precision(t_data *data, char *buffer, int *i, int nbr)
{
	// precision ajoute des zeros devant le nbr avant
	if ((int)(data->format.precision - ft_intlen(nbr)) <= 0)
		return ;
	while ((data->format.precision-- - ft_intlen(nbr)) && !data->format.zero)
		buffer[(*i)++] = '0';
	return ;
}

static void	ft_add_width(t_data *data, char *buffer, int *i, int nbr)
{
	int	padding_size;

	if (data->format.precision && ((int)(data->format.precision - ft_intlen(nbr)) > 0))
		padding_size = data->format.width - (ft_strlen(buffer)
				+ data->format.precision);
	else
		padding_size = data->format.width - (ft_strlen(buffer)
				+ ft_intlen(nbr));
	if (padding_size > 0)
	{
		if (data->format.minus)
		{
			ft_add_precision(data, buffer, i, nbr);
			ft_addnbr_base((buffer + *i), i, nbr, "0123456789");
			while (padding_size--)
				buffer[(*i)++] = data->format.width_char;
		}
		else if (!data->format.minus)
		{
			while (padding_size--)
				buffer[(*i)++] = data->format.width_char;
			ft_add_precision(data, buffer, i, nbr);
			ft_addnbr_base((buffer + *i), i, nbr, "0123456789");
		}
	}
	return ;
}

static void	ft_fullfill_d(t_data *data, long nbr)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc(sizeof(char) * 4096);
	if (!buffer)
		return ;
	// espace or plus
	i = 0;
	if (data->format.space)
		buffer[i++] = ' ';
	else if (nbr < 0)
	{
		buffer[i++] = '-';
		nbr = ft_abs(nbr);
	}
	else if (data->format.plus)
		buffer[i++] = '+';
	// 0 + width
	if (((ft_strlen(buffer) + ft_intlen(nbr)) < data->format.width))
		ft_add_width(data, buffer, &i, nbr);
	else
	{
		ft_add_precision(data, buffer, &i, nbr);
		ft_addnbr_base((buffer + i), &i, nbr, "0123456789");
	}
	ft_alter_data(data, buffer);
	return ;
}

void	ft_alter_d(t_data *data)
{
	//[-+ 0][width][precision]
	if (data->format.zero)
		data->format.width_char = '0';
	// TODO protection des cas exceptionnels
	ft_fullfill_d(data, va_arg(data->ap, int));
	return ;
}

// exceptionnnels
/*
' ' avec '+' est interdit
'0' avec '-' est interdit
'0' avec precision est interdit
*/

//' ' ajoute un seul espace espace > (0 + width)
//' ' > '-'
//'0' seul ne fait rien (width >= 1)
// precision > width (width ne fait rien si ft_strlen(buffer) >= width)
// precision agit comme '0' il ajoute des zeros dans le buffer
// width sans '0' ajoute des espaces
// with avec '0' ajoute des zero a la place des espaces

// (' ' | +) > precision > justify > width
// (' ' | +) > (0 + width) ==>
//		si on a un ' ' alors le nombre de zero est de len_nbr(nbr) - (width- 1)
//		sinon si on a pas un ' ' alors le nombre de zero est de len_nbr(nbr)
//			- width