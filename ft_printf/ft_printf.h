/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:44:12 by mushu             #+#    #+#             */
/*   Updated: 2021/04/12 11:18:35 by ybrutout         ###   ########.fr       */
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
	int		width;
	int		precision;
	int		dot;
	int		minus;
	int		zero;
	int		type;
	char	*str;
	int		size;

}	t_point;

int			ft_printf(const char *format, ...);
int			ft_check_type(char *form, t_point *conv);
int			ft_write(char *str, int a);
int			ft_check_form(char c);
int			ft_check_flag(char *form, t_point *conv);
int			ft_check_width(char *form, t_point *conv, va_list arg);
int			ft_check_precision(char *form, t_point *conv, va_list arg);
int			ft_strlen_nb(long i, int base);
int			ft_strlen(char *str);
int			ft_conv_flags(va_list arg, t_point *conv);

char		*ft_conv_flags_c(va_list arg, t_point *conv);
char		*ft_putnbr(int nb);
char		*ft_conv_c(char c);
char		*ft_conv_d(int i);
char		*ft_conv_s(char	*str);
char		*ft_conv_p_1(void *adress);
char		*ft_conv_d(int j);
char		*ft_conv_X_1(int i);
char		*ft_cpy(char *dst, int flag, t_point conv, int src_size);

void		ft_free(char **str);
void		ft_cln(t_point *conv);

#endif
