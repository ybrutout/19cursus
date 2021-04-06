/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:44:12 by mushu             #+#    #+#             */
/*   Updated: 2021/04/06 15:27:02 by ybrutout         ###   ########.fr       */
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
	int     width;
	int		precision;
	int		dot;
	int		minus;
	int		zero;
	int    type;
	char	*str;

} t_point;

int			ft_printf(const char *format, ...);
int			ft_check_type(char *form, t_point *conv);
int			ft_write(char *str, int a);
int			ft_strlen_nb(long i, int base);
int			ft_check_form(char c);
int			ft_check_flag(char *form, t_point *conv);
int			ft_check_width(char *form, t_point *conv, va_list arg);
int			ft_check_precision(char *form, t_point *conv, va_list arg);

char		*ft_putnbr(int nb);
char		*ft_conv_c(va_list arg);
char		*ft_conv_d(int i);
char		*ft_conv_s(char	*str);
char		*ft_conv_p(void *adress);
char		*ft_conv_d(int j);

void        ft_free(char **str);
void		ft_cln(t_point *conv);

#endif
