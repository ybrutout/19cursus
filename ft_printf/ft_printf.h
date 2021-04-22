/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:44:12 by mushu             #+#    #+#             */
/*   Updated: 2021/04/22 16:24:32 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_point
{
	int		width;
	int		precision;
	int		dot;
	int		minus;
	int		zero;
	int		type;
	int		size;

}	t_point;

int			ft_write(char str, int a);
int			ft_printf(const char *format, ...);
int			ft_check_type(char *form, t_point *conv);
int			ft_check_form(char c);
int			ft_check_flag(char *form, t_point *conv);
int			ft_check_width(char *form, t_point *conv, va_list arg);
int			ft_check_precision(char *form, t_point *conv, va_list arg);
int			ft_strlen_nb(unsigned long long int i, int base);
int			ft_strlen(char *str);
int			ft_conv_flags(va_list arg, t_point *conv);

void		ft_cln(t_point *conv);
void		ft_conv_flags_d(int i, t_point *conv);
void		ft_conv_flags_p(void *adress, t_point *conv);
void		ft_conv_flags_u(unsigned int i, t_point *conv);
void		ft_conv_flags_x(unsigned long long int nb, t_point *conv);
void		ft_conv_flags_X_(unsigned long long int nb, t_point *conv);
void		ft_putnbr(unsigned long long int nb, int base, char *str_base);
void		ft_0x(void);
#endif
