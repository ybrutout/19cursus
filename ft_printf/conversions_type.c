/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mushu <mushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:28:40 by mushu             #+#    #+#             */
/*   Updated: 2021/03/04 18:55:30 by mushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_conv_d(int j)
{
	int			i;
	int			j_bis;
	char		*str;

	i = 0;
	j_bis = j;
	while (j_bis >= 10)
	{
		i++;
		j_bis = j_bis / 10;
	}
	if (!(str = (char *) malloc(sizeof(char) * i + 2)))
		return (NULL);
	str[i + 1] = 0;
	i = 0;
	if (j < 0)
	{
		str[i++] = '-';
		j *= -1;
	}
	if (j >= 10)
		ft_conv_d(j / 10);
	printf("j = %d", j % 10);
	str[i++] = (j % 10) + 48;
	return (str);
}

char			*ft_conv_c(va_list arg)
{
	char	*str;
	char	c;
	
	if (!(str = (char *)malloc(sizeof (char) * 2)))
		return (NULL);
	c = va_arg(arg, int);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

int				ft_conv_type(char *form, va_list arg)
{
	t_point 	conv;
	int			i;

	if (*form == 'c')
	{
		if (!(conv.str = ft_conv_c(arg)))
			return (0);
	}
	else if(*form == 'd')
	{
		i = va_arg(arg, int);
		if(!(conv.str = ft_conv_d(i)))
			return (0);
	}
	ft_write(conv.str);
	free(conv.str);
	return (1);
}
