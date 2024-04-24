/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:51:13 by hramaros          #+#    #+#             */
/*   Updated: 2024/04/24 07:44:31 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

int	ft_sendsize(const unsigned int serverPid, const unsigned int size)
{
	if (write(0, &size, sizeof(unsigned int)))
		if (kill(serverPid, SIGUSR1) == 0)
			return (1);
	return (0);
}

int	ft_sendmessage(const unsigned int server_pid, const char *message)
{
	if (write(0, message, ft_strlen(message)))
		if (kill(server_pid, SIGUSR2) == 0)
			return (1);
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
			60) exit(0);
	}
	server_pid = ft_atoi(argv[1]);
	message_len = ft_strlen(argv[2]);
	if (!ft_sendsize(server_pid, message_len) || !ft_sendmessage(server_pid,
			argv[2]))
	{
		ft_printf("\nMessage non envoye au serveur %d, quitte le programme.",
			server_pid);
		exit(1);
	}
	ft_printf("PID: %d\nMessage: '%s'\n", getpid(), argv[2]);
	return (0);
}
