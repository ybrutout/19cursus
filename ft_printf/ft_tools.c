/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:17:37 by mushu             #+#    #+#             */
/*   Updated: 2021/04/14 15:35:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char		*new_dst;
	const char	*new_src;
	size_t		i;

	if (dst == NULL && src == NULL)
		return (NULL);
	new_dst = (char *)dst;
	new_src = (const char *)src;
	i = 0;
	while (i < n)
	{
		new_dst[i] = new_src[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *s1)
{
	char	*new_s1;
	int		i;

	i = ft_strlen(s1) + 1;
	new_s1 = (char *)malloc(sizeof(char) * i);
	if (!(new_s1))
		return (0);
	ft_memcpy(new_s1, s1, i);
	return (new_s1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

void	ft_cln(t_point *conv)
{
	conv->dot = 0;
	conv->minus = 0;
	conv->precision = 0;
	conv->width = 0;
	conv->zero = 0;
	conv->type = 0;
	conv->size = 0;
}

int	ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strlen_nb(long i, int base)
{
	long int	len;

	len = 0;
	if (i < 0)
	{
		i *= -1;
		len++;
	}
	while (i > base - 1)
	{
		i = i / base;
		len++;
	}
	len = len + 1;
	return (len);
}

char	*ft_cpy(char *dst, int flag, t_point conv, int src_size)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = conv.str;
	if (flag > 9)
		dst[conv.precision--] = '\0';
	if (flag < 9)
	{
		if (conv.width < src_size)
			conv.width = src_size;
		dst[conv.width--] = '\0';
	}
	if (flag == 0)
	{
		while (conv.width >= 0 || src_size > -1)
		{
			if (--src_size > -1)
				dst[conv.width--] = str[src_size];
			else if (src_size <= -1)
			{
				dst[conv.width--] = ' ';
			}
		}
	}
	else if (flag == 1)
	{
		while (i <= conv.width)
		{
			if (src_size-- > 0)
			{
				dst[i++] = str[j++];
			}
			else
				dst[i++] = ' ';
		}
	}
	else if (flag == 2)
	{
		while (conv.width >= 0)
		{
			if (--src_size > -1)
				dst[conv.width--] = str[src_size--];
			else if (src_size <= -1)
				dst[conv.width--] = '0';
		}
	}
	else if (flag == 10)
	{
		while (conv.precision >= 0)
		{
			if (--src_size > -1)
				dst[conv.precision--] = str[src_size];
			else if (src_size <= -1)
				dst[conv.precision--] = ' ';
		}
	}
	return (dst);
}
