/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:51:13 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/04 06:50:14 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

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

int	main(int argc, char **argv)
{
	int	server_pid;
	int	message_len;

	if (argc < 3)
	{
		write(1, "\nUtilisation: ./client [PID du serveur] [chaine]\n", 49);
		write(1,
			"\nExemple: ./client 4242 'bonjour c'est le projet Minitalk'\n\n",
			60);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (!ft_sendmessage(server_pid, argv[2]))
	{
		ft_printf("\nMessage non envoye au serveur %d, quitte le programme.",
			server_pid);
		return (1);
	}
	ft_printf("PID: %d\nMessage: '%s'\n", getpid(), argv[2]);
	return (0);
}
