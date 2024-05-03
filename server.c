/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:51:06 by hramaros          #+#    #+#             */
/*   Updated: 2024/04/27 10:47:06 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_CHAR 2048

typedef struct s_data
{
	char			*buffer;
	char			c;
	unsigned int	bit_index;
}					t_data;

void	ft_add_bit_one(void)
{
	void bit_mask;

	bit_mask = 0b10000000;
	
}

void	ft_add_bit_one(void)
{
}

int	ft_init_data(t_data *data)
{
	data->buffer = malloc(sizeof(unsigned char) * MAX_CHAR);
	if (!data->buffer)
		return (0);
	data->c = 0;
	data->bit_index = 0;
	return (1);
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_add_bit_one();
	else if (sig == SIGUSR2)
		ft_add_bit_zero();
	return ;
}

t_data				data;

int	main(void)
{
	struct sigaction	mngt;
	sigset_t			mask;

	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	mngt.sa_mask = mask;
	mngt.sa_handler = sig_handler;
	if (!ft_init_data(data))
	{
		write(1, "There was an error for global variable allocation ...\n", 53);
		return (1);
	}
	sigaction(SIGUSR1, &mngt, NULL);
	sigaction(SIGUSR2, &mngt, NULL);
	ft_printf("Server started... PID: %d\n\n", getpid());
	while (1)
	{
		
		nsleep(100);
		printf("%s\n", data.buffer);
	}
	return (0);
}
