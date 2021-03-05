/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mushu <mushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:44:12 by mushu             #+#    #+#             */
/*   Updated: 2021/03/04 17:59:41 by mushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_point
{
	int     d;
	char    c;
	char	*str;
} t_point;

int			ft_printf(const char *format, ...);
int			ft_conv_type(char *form, va_list arg);

char		*ft_putnbr(int nb);
char		*ft_conv_c(va_list arg);
char		*ft_conv_d(int i);

void		ft_write(char *str);
void        ft_free(char **str);

#endif