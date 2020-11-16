/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strl_cat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:50:31 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/16 15:51:24 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_size(char *dest, char *src, int *i, int *j)
{
	while (dest[*i] != '\0')
	{
		i++;
	}
	while (src[*j] != '\0')
	{
		j++;
	}
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	sd;
	int	ssrc;
	int	i;
	int	j;
	int	size_try;

	sd = 0;
	ssrc = 0;
	j = 0;
	ft_size(dest, src, &sd, &ssrc);
	i = sd;
	if ((int)size >= sd + ssrc - 1)
	{
		while (src[j])
		{
			dest[sd] = src[j];
			sd++;
			j++;
		}
		dest[sd] = '\0';
		size_try = i + ssrc;
	}
	else
		size_try = ssrc + i - 1;
	return (size_try);
}