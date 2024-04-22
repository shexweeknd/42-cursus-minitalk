/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:41:16 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/11 07:28:58 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addchar_i(char *buffer, int *index_ptr, char c)
{
	buffer[*index_ptr] = c;
	*index_ptr += 1;
}
