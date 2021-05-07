/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:25:54 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/07 16:45:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nb_wrd(char const *s, char sep)
{
	int	i;
	int	count;

	if (s == 0 || s[0] == 0)
		return (0);
	i = 1;
	count = 0;
	if (s[0] != sep)
		count++;
	while (s[i] != '\0')
	{
		if (s[i] != sep && s[i - 1] == sep)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_malloc(char const *s, char sep)
{
	int		len;
	char	**new_s;

	len = ft_nb_wrd(s, sep);
	new_s = malloc(sizeof(*new_s) * (len + 1));
	if (new_s == 0)
		return (0);
	return (new_s);
}

static int	ft_next_wrd(char const *s, char sep, int i)
{
	int	count;

	count = 0;
	while (s[i] == sep && s[i] != '\0')
	{
		i++;
	}
	while (s[i] != '\0' && s[i] != sep)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **str_tab, int i)
{
	int	j;

	j = 0;
	while (j < i && str_tab[j] != 0)
	{
		free(str_tab[j]);
		j++;
	}
	free(str_tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**new_s;

	if (s == 0)
		return (0);
	i = -1;
	new_s = ft_malloc(s, c);
	if (!new_s)
		return (0);
	while (++i < ft_nb_wrd(s, c))
		ft_split_2(new_s, c, s, i);
	new_s[i] = 0;
	return (new_s);
}
