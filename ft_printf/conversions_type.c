/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:28:40 by mushu             #+#    #+#             */
/*   Updated: 2021/03/05 18:37:45 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_strlen_nb(int i)
{
	int	len;

	len = 0;
	if(i < 0)
	{
		i *= -1;
		len++;
	}
	while (i > 9)
	{
		i = i / 10;
		len++;
	}
	len = len + 1;
	return (len);
}

int				ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_conv_d(int j)
{
	char		*str;
	int			size;

	size = ft_strlen_nb(j);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	str[size--] = '\0';
	if (j < 0)
	{
		str[0] = '-';
		j *= -1;
	}
	while(j)
	{
		str[size--] = j % 10 + 48;
		j = j / 10;
	}
	return (str);
}

char			*ft_conv_c(va_list arg)
{
	char	*str;
	
	if (!(str = (char *)malloc(sizeof (char) * 2)))
		return (NULL);
	str[0] = va_arg(arg, int);
	str[1] = '\0';
	return (str);
}

char			*ft_conv_s(char	*str)
{
	char		*nw_str;
	int			size;
	int			i;

	size = ft_strlen(str);
	i = -1;
	if(!(nw_str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (str[++i])
		nw_str[i] = str[i];
	return (nw_str);
}

void			ft_con_p(void * address)
{	
	printf("void * = %s\n", (char *)address);
}

int				ft_conv_type(char *form, va_list arg)
{
	t_point 	conv;

	if (*form == 'c')
	{
		if (!(conv.str = ft_conv_c(arg)))
			return (0);
	}
	else if(*form == 'd')
	{
		if(!(conv.str = ft_conv_d(va_arg(arg, int))))
			return (0);
	}
	else if (*form == 's')
	{
		if (!(conv.str = ft_conv_s(va_arg(arg, char*))))
			return(0);
	}
	else if(*form == 'p')
	{
		ft_con_p(va_arg(arg, void*));
	}
	ft_write(conv.str, 1);
	free(conv.str);
	return (1);
}
