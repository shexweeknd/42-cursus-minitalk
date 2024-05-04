/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:19:36 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/04 12:31:00 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct s_data
{
	char			*buffer;
	unsigned int	buffer_index;
	char			c;
	unsigned int	bit_index;
}					t_data;

typedef struct s_client_data
{
	pid_t			server_pid;
	char			*buffer;
}					t_client_data;

#endif
