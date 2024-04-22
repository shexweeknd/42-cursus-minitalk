/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:22:20 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/12 08:05:02 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include "ft_bonus.h"

static size_t	ft_isset(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_flush(t_data *data)
{
	// ft_flush print tout ce au'il y a dans le buffer et puis remet le buffer index a ainsi que le buffer a 0
	if (*data->buffer)
		data->printed += write(1, data->buffer, data->buffer_index);
	ft_memset(data->buffer, 0, sizeof(char) * 4096);
	data->buffer_index = 0;
	return (data->printed);
}

static void	ft_alter_buffer(t_data *data, int c)
{
	if (data->buffer_index == 4096)
		ft_flush(data);
	else
	{
		data->buffer[data->buffer_index] = (char)c;
		data->buffer_index += 1;
	}
	return ;
}

static void	ft_reset_format(t_format *format)
{
	format->minus = 0;
	format->plus = 0;
	format->space = 0;
	format->zero = 0;
	format->dash = 0;
	format->width = 0;
	format->width_char = ' ';
	format->dot = 0;
	format->precision = 0;
	return ;
}

static void	ft_parse_on_buffer(t_data *data)
{
	if (*data->str == '%')
		ft_alter_buffer(data, '%');
	else if (*data->str == 'c')
		ft_alter_c(data);
	// TODO faire des flags de spdiuxX%
	else if (*data->str == 's')
		ft_alter_s(data);
	else if (*data->str == 'p')
		ft_alter_p(data);
	else if (*data->str == 'd' || *data->str == 'i')
		ft_alter_d(data);
	else if (*data->str == 'u')
		ft_alter_u(data);
	else if (*data->str == 'x')
		ft_alter_x(data); 
	else
		ft_alter_buffer(data, *data->str);
	ft_reset_format(&(data->format));
	return ;
}

static void	ft_get_format(t_data *data)
{
	// tant qu'on a pas trouve le specificateur, on itere
	while (!ft_isset(*data->str, "cspdiuxX"))
	{
		// check flags [+- 0#]
		if (*data->str == '-' && *++data->str)
			data->format.minus = 1;
		else if (*data->str == '+' && *++data->str)
			data->format.plus = 1;
		else if (*data->str == '0' && !data->format.dot && *++data->str)
			data->format.zero = 1;
		else if (*data->str == ' ' && *++data->str)
			data->format.space = 1;
		else if (*data->str == '#' && *++data->str)
			data->format.dash = 1;
		// check width
		else if (ft_atoi(data->str) && !data->format.dot)
		{
			data->format.width = ft_atoi(data->str);
			data->str += (ft_ullen(data->format.width));
		}
		// check precision
		else if (*data->str == '.')
		{
			data->format.dot = 1;
			data->format.precision = ft_atoi((data->str + 1));
			data->str += (ft_ullen(data->format.precision));
		}
		else
			data->str++;
	}
	ft_parse_on_buffer(data);
	return ;
}

static void	ft_init_data(t_data *data, char *str)
{
	data->str = str;
	data->buffer_index = 0;
	data->printed = 0;
	ft_reset_format(&(data->format));
	return ;
}

int	ft_printf(const char *str, ...)
{
	t_data			data;
	unsigned int	printed;

	data.buffer = (char *)malloc(sizeof(char) * 4096);
	if (!data.buffer)
		return (-1);
	va_start(data.ap, str);
	ft_init_data(&data, str);
	while (*data.str)
	{
		if (*data.str == '%' && *++data.str != '\0')
			ft_get_format(&data);
		else
			ft_parse_on_buffer(&data);
		data.str++;
	}
	printed = ft_flush(&data);
	va_end(data.ap);
	free(data.buffer);
	return (printed);
}

// algorithm
/*

1 - create struct to store data
	actual pointer
	the ap
	the chars written
	the buffer
	the buffer index
	the format associated with the actual iteration in it

2 - create a struct to store flags, width, and precision
	0 for each flag is unset
	1 for each flag is set
	!! width flag must be different than zero
	precision can be zero but must be seen after '.'

3 - create a buffer that stores the char and its already printed value

4 - store into the buffer until you see the % sign

5 - parse the flags if incountered % sign

6 - flush the buffer at the end of the day

*/