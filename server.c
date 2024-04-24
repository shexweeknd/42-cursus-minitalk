/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:51:06 by hramaros          #+#    #+#             */
/*   Updated: 2024/04/24 06:59:43 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int	main(void)
{
	int size;
	int pipe;
	int fd;

	pipe = mkfifo(".fifo", 0777);
	if (pipe == -1)
	{
		return (1);
	}
	fd = open(".fifo", O_RDONLY);
	if (fd == -1)
	{
		return (2);
	}
	// ft_printf("Server started... PID: %d\n\n", getpid());
	read(fd, &size, sizeof(int) * 1);

	return (0);
}