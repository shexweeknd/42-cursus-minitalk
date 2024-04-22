/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alter_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:29:21 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/09 14:18:22 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static void	ft_dump_data(t_data *data, char *buffer)
{
	int	i;
	int	len;

	len = ft_strlen(buffer);
	i = 0;
	while (i < len)
		data->buffer[data->buffer_index++] = buffer[i++];
	free(buffer);
	return ;
}

static void	ft_dump_arr_buffer(char *addr, char *arr)
{
	if (*arr == '0' && *(arr + 1) == '0' && addr[ft_strlen(addr) - 1] == 'x')
		return ;
	if (*(arr) == '0' && addr[ft_strlen(addr) - 1] == 'x')
	{
		ft_strlcat(addr, arr + 1, ft_strlen(addr) + ft_strlen(arr + 1) + 1);
		return ;
	}
	ft_strlcat(addr, arr, ft_strlen(addr) + ft_strlen(arr) + 1);
	return ;
}

static char	*ft_create_addr(void *ptr)
{
	unsigned int	i;
	char			b_arr[sizeof(unsigned int *)];
	char			arr[3];
	char			*hex;
	char			*addr;

	hex = "0123456789abcdef";
	addr = (char *)calloc(4096, sizeof(char));
	if (!addr)
		return (NULL);
	ft_bzero(addr);
	i = 0;
	if (!ptr)
	{
		ft_strlcat(addr, "(nil)", 6);
		return (addr);
	}
	while (i < sizeof(unsigned int *))
	{
		b_arr[i] = ((char *)&ptr)[i];
		i++;
	}
	ft_strlcat(addr, "0x", 3);
	while (i > 0)
	{
		arr[0] = hex[((char)b_arr[i - 1] >> 4) & 0xf];
		arr[1] = hex[(char)b_arr[i-- - 1] & 0xf];
		arr[2] = '\0';
		ft_dump_arr_buffer(addr, arr);
	}
	return (addr);
}

static void	ft_fullfill_p(t_data *data, void *ptr)
{
	int		i;
	char	*addr;
	long	padding_size;

	i = 0;
	addr = ft_create_addr(ptr);
	padding_size = data->format.width - ft_strlen(addr);
	if (padding_size <= 0)
	{
		return (ft_dump_data(data, addr));
	}
	else if (data->format.minus && padding_size > 0)
	{
		ft_dump_data(data, addr);
		while (padding_size--)
			data->buffer[data->buffer_index++] = ' ';
	}
	else if (!data->format.minus && padding_size > 0)
	{
		while (padding_size--)
			data->buffer[data->buffer_index++] = ' ';
		ft_dump_data(data, addr);
	}
	return ;
}

void	ft_alter_p(t_data *data)
{
	//[-][width]
	// width > justify
	ft_fullfill_p(data, va_arg(data->ap, void *));
	return ;
}