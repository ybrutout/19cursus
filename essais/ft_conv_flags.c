/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:30:46 by mushu             #+#    #+#             */
/*   Updated: 2021/04/15 09:25:17 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_flags_c(va_list arg, t_point *conv)
{
	char	*nw_str;

	conv->size = 1;
	conv->str = ft_conv_c(va_arg(arg, int));
	if (!conv->str)
		return (NULL);
	if (conv->width >= 1)
	{
		nw_str = (char *)malloc(sizeof(char) * (conv->width) + 1);
		if (!nw_str)
			return (0);
		if (conv->minus == 1)
			ft_cpy(nw_str, 1, *conv, 1);
		else if (conv->zero == 1)
			ft_cpy(nw_str, 2, *conv, 1);
		else
			ft_cpy(nw_str, 0, *conv, 1);
		free(conv->str);
		conv->size = conv->width;
	}
	else
	{
		nw_str = conv->str;
		conv->size = 1;
	}
	return (nw_str);
}

char	*ft_conv_flags_prct(t_point *conv)
{
	char	*nw_str;
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	conv->str = str;
	if (conv->width >= 1)
	{
		nw_str = (char *)malloc(sizeof(char) * (conv->width) + 1);
		if (!nw_str)
			return (NULL);
		if (conv->minus == 1)
			ft_cpy(nw_str, 1, *conv, 1);
		else if (conv->zero == 1)
			ft_cpy(nw_str, 2, *conv, 1);
		else
			ft_cpy(nw_str, 0, *conv, 1);
		free(str);
		conv->size = conv->width;
	}
	else
	{
		conv->size = 1;
		return(str);
	}
	return (nw_str);
}

char	*ft_conv_flags_s(va_list arg, t_point *conv)
{
	char	*nw_str;
	char	*tp;

	tp = va_arg(arg, char *);
	conv->str = ft_conv_s(tp);
	if (!conv->str)
		return (NULL);
	if (conv->dot == 1 && conv->precision < ft_strlen(conv->str) && tp)
	{
		nw_str = malloc(sizeof(char) * (conv->precision + 1));
		if (!nw_str)
			return (NULL);
		ft_cpy(nw_str, 10, *conv, conv->precision);
		free(conv->str);
		conv->str = nw_str;
	}
	if (conv->width > 0)
	{
		nw_str = malloc(sizeof(char) * (conv->width + 1));
		if (!nw_str)
			return (NULL);
		if (conv->minus == 1)
			ft_cpy(nw_str, 1, *conv, ft_strlen(conv->str));
		else
			ft_cpy(nw_str, 0, *conv, ft_strlen(conv->str));
		if (conv->width > ft_strlen(conv->str))
			conv->size = conv->width;
		else
			conv->size = ft_strlen(conv->str);
		free(conv->str);
	}
	else
	{
		conv->size = ft_strlen(conv->str);
		return(conv->str);
	}
	return (nw_str);
}

int	ft_conv_flags(va_list arg, t_point *conv)
{
	if (conv->type == 1)
	{
		conv->str = ft_conv_flags_c(arg, conv);
		if (!conv->str)
			return (0);
	}
	if (conv->type == 10)
	{
		conv->str = ft_conv_flags_prct(conv);
		if (!conv->str)
			return (0);
	}
	if (conv->type == 3)
	{
		conv->str = ft_conv_flags_s(arg, conv);
		if (!conv->str)
			return (0);
	}
	ft_write(conv->str, conv->size);
	ft_cln(conv);
	free(conv->str);
	return (1);
}
