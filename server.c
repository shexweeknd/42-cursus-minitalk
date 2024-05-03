/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:51:06 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/03 07:22:31 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_CHAR 2048

t_data	g_data;

int	ft_init_data(t_data *g_data)
{
	g_data->buffer = malloc(sizeof(unsigned char) * MAX_CHAR);
	if (!g_data->buffer)
		return (0);
	g_data->c = 0;
	g_data->bit_index = 0;
	g_data->buffer_index = 0;
	return (1);
}

void	sig_handler(int sig)
{
	unsigned char	bit_mask;

	bit_mask = 0b10000000;
	if (sig == SIGUSR1)
	{
		g_data.c = (g_data.c | (bit_mask >> g_data.bit_index));
		if (g_data.bit_index++ >= 8)
		{
			g_data.bit_index == 0;
			g_data.buffer[g_data.buffer_index++] = g_data.c;
		}
	}
	else if (sig == SIGUSR2)
	{
		g_data.bit_index++;
		if (g_data.bit_index++ >= 8)
		{
			g_data.bit_index == 0;
			g_data.buffer[g_data.buffer_index++] = g_data.c;
		}
	}
	if (g_data.c == 0)
		ft_printf("%s\n", g_data.buffer);
	return ;
}

int	main(void)
{
	struct sigaction	mngt;
	sigset_t			mask;

	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	mngt.sa_mask = mask;
	mngt.sa_handler = sig_handler;
	if (!ft_init_data(&g_data))
	{
		write(1, "There was an error for global variable allocation ...\n", 53);
		return (1);
	}
	sigaction(SIGUSR1, &mngt, NULL);
	sigaction(SIGUSR2, &mngt, NULL);
	ft_printf("Server started... PID: %d\n\n", getpid());
	while (1)
		usleep(100);
	return (0);
}
