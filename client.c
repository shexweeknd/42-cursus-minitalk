/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:51:13 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/04 13:12:38 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "minitalk.h"
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

t_client_data	g_data;

int	ft_send_ending(const unsigned int server_pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (kill(server_pid, SIGUSR2) == -1)
			return (0);
		usleep(50);
	}
	return (1);
}

int	ft_send_char(const unsigned int server_pid, unsigned char c)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				return (0);
		}
		bit >>= 1;
		usleep(50);
	}
	return (1);
}

int	ft_sendmessage(const unsigned int server_pid, const char *message)
{
	unsigned int	char_numbers;

	char_numbers = 0;
	while (*message)
	{
		if (!ft_send_char(server_pid, *message++))
			return (0);
		char_numbers++;
	}
	if (!ft_send_ending(server_pid))
		return (0);
	ft_printf("char numbers : %d\n", char_numbers);
	return (1);
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("recepteur: %d\nMessage envoye: '%s'\n", g_data.server_pid,
			g_data.buffer);
	kill(getpid(), SIGUSR2);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc < 3)
	{
		ft_printf("\nUtilisation: ./client [PID du serveur] [chaine]\n\nExemp");
		ft_printf("le: ./client 4242 'bonjour c'est le projet Minitalk'\n\n");
		return (1);
	}
	g_data.server_pid = ft_atoi(argv[1]);
	g_data.buffer = ft_strdup(argv[2]);
	if (!g_data.buffer)
	{
		ft_printf("erreur d'allocation: quitte le programme");
		return (2);
	}
	signal(SIGUSR1, sig_handler);
	if (!ft_sendmessage(g_data.server_pid, g_data.buffer))
	{
		ft_printf("\nMessage non envoye au serveur %d, quitte le programme.",
			server_pid);
		return (3);
	}
	while (1)
		;
	return (0);
}
