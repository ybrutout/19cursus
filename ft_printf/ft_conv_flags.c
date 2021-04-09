/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:30:46 by mushu             #+#    #+#             */
/*   Updated: 2021/04/09 16:03:38 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_flags_c(va_list arg, t_point *conv)
{
	char	*nw_str;

	conv->str = ft_conv_c(va_arg(arg, int));
	if (!conv->str)
		return (NULL);
	if (conv->width >= 1)
	{
		nw_str = (char *)malloc(sizeof(char) * (conv->width) + 1);
		if (!nw_str)
			return (0);
		if (conv->minus == 1)
			ft_cpy(nw_str, conv->str, 1, conv->width);
		else if (conv->zero == 1)
			ft_cpy(nw_str, conv->str, 2, conv->width);
		else
			ft_cpy(nw_str, conv->str, 0, conv->width);
		free(conv->str);
	}
	else
		nw_str = conv->str;
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
	if (conv->width >= 1)
	{
		nw_str = (char *)malloc(sizeof(char) * (conv->width) + 1);
		if (!nw_str)
			return (0);
		if (conv->minus == 1)
			ft_cpy(nw_str, str, 1, conv->width);
		else if (conv->zero == 1)
			ft_cpy(nw_str, str, 2, conv->width);
		else
			ft_cpy(nw_str, str, 0, conv->width);
		free(str);
	}
	else
		nw_str = str;
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
		conv->str = ft_conv_flags_prct( conv);
	}
	ft_write(conv->str, 1);
	ft_cln(conv);
	free(conv->str);
	return (1);
}
