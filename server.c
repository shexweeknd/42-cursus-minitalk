/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:51:06 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/04 13:08:51 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minitalk.h"
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_CHAR 65536

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

void	ft_alter_data(pid_t pid)
{
	g_data.bit_index = 0;
	g_data.buffer[g_data.buffer_index++] = g_data.c;
	if (!g_data.c)
	{
		ft_printf("Message received from %d: %s\n\n", pid, g_data.buffer);
		if (kill(pid, SIGUSR1) == -1)
			ft_printf("\nConnexion to %d got interrupted...\n");
		if (!ft_init_data(&g_data))
			ft_printf("Global Variable Error, leaving ...\n");
	}
	g_data.c = 0;
}

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	unsigned char	bit_mask;

	bit_mask = 0b10000000;
	if (sig == SIGUSR1)
	{
		g_data.c = (g_data.c | (bit_mask >> g_data.bit_index++));
		if (g_data.bit_index == 8)
			ft_alter_data(info->si_pid);
	}
	else if (sig == SIGUSR2)
	{
		g_data.bit_index++;
		if (g_data.bit_index == 8)
			ft_alter_data(info->si_pid);
	}
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
	mngt.sa_sigaction = sig_handler;
	if (!ft_init_data(&g_data))
	{
		write(1, "There was an error for global variable allocation ...\n", 53);
		return (1);
	}
	ft_printf("Server started... PID: %d\n\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &mngt, NULL);
		sigaction(SIGUSR2, &mngt, NULL);
	}
	return (0);
}
