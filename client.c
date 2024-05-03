/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:51:13 by hramaros          #+#    #+#             */
/*   Updated: 2024/04/27 09:35:19 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int	ft_sendmessage(const unsigned int server_pid, const char *message)
{
	if (ft_strlen(message) > 3)
	{
		if (kill(server_pid, SIGUSR1) == 0)
			return (1);
	}
	else
	{
		if (kill(server_pid, SIGUSR2) == 0)
			return (1);
	}
	return (0);
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
