/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alter_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:40:23 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/09 07:39:21 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static char *ft_strndup(const char *s, size_t n)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < n && s[i])
	{
		*(ret + i) = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);

}

static void ft_dup_arg(t_data *data, char *s)
{
	while (*s)
		data->buffer[data->buffer_index++] = *s++;
	return ;
}

static void	ft_fullfill_s(t_data *data, char *s)
{
	size_t		i;
	size_t	padding_size;
	char	*tmp;

	// precision sur s truncate when presicion < strlen(s)
	i = 0;
	while (i < data->format.precision && s[i] && data->format.dot)
		i++;
	if (!data->format.dot)
		i = ft_strlen(s);
	tmp = ft_strndup(s, i);
	if (!tmp)
		return ;
	padding_size = data->format.width - i;
	// justify left
	if (data->format.minus)
	{
		i = 0;
		while (tmp[i])
			data->buffer[data->buffer_index++] = tmp[i++];
		while (padding_size-- && (data->format.width > i))
			data->buffer[data->buffer_index++] = ' ';
	}
	else if (!data->format.minus)
	{
		i = 0;
		while (padding_size-- && (data->format.width > i))
			data->buffer[data->buffer_index++] = ' ';
		while (tmp[i])
			data->buffer[data->buffer_index++] = tmp[i++];
	}
	free(tmp);
	return ;
}

void	ft_alter_s(t_data *data)
{
	// precision > justify > width
	//[-+][width][precision]
	ft_fullfill_s(data, va_arg(data->ap, char *));
	return ;
}
