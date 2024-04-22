/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:59:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/12 08:16:28 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BONUS_H
# define FT_BONUS_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	//[-+' '0]
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				dash;
	size_t			width;
	char			width_char;
	int				dot;
	size_t			precision;
}					t_format;

typedef struct s_data
{
	char			*str;
	va_list			ap;
	char			*buffer;
	unsigned int	buffer_index;
	unsigned int	printed;
	t_format		format;
}					t_data;

/*main function*/
int					ft_printf(const char *str, ...);

/*altering functions*/
void				ft_alter_c(t_data *data);
void				ft_alter_s(t_data *data);
void				ft_alter_p(t_data *data);
void				ft_alter_d(t_data *data);
void				ft_alter_u(t_data *data);
void				ft_alter_x(t_data *data);

/*utils functions*/
void				ft_addnbr_base(char *buffer, int *index_ptr, long nbr,
						char *base);
void				ft_addchar_i(char *buffer, int *index_ptr, char c);
void				ft_addx(char *buffer, unsigned int nbr, char *base);
size_t				ft_ullen(unsigned long nbr);
size_t				ft_intlen(int nbr);
long				ft_abs(int nbr);

#endif