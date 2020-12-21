/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:25:54 by ybrutout          #+#    #+#             */
/*   Updated: 2020/12/21 16:41:41 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_count_sep(char const *s, char c)
{
	unsigned int		i;
	unsigned int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] == c) && !(s[i + 1] == c) && (s[i + 1] != '\0'))
			count++;
		i++;
	}
	if (s[0] != c)
		count++;
	return (count);
}

static int				ft_count_ch(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	if (i > 0)
		i++;
	return (i);
}

static char				ft_free(char **new, int j)
{
	while (j >= 0)
	{
		free(new[j]);
		j--;
	}
	free(new);
	return (0);
}

static int				ft_str(char const *s, char c, char **new, int nb_word)
{
	int		nb_ch;
	int		j;
	int		i;

	j = 0;
	i = -1;
	while (s[++i] && j <= nb_word)
	{
		nb_ch = ft_count_ch(&s[i], c);
		if (nb_ch > 0)
		{
			new[j] = (char *)malloc(sizeof(char) * nb_ch);
			if (!new[j])
			{
				ft_free(new, j - 1);
				return (0);
			}
			ft_strlcpy(new[j], &s[i], nb_ch);
			i = i + nb_ch - 1;
			nb_ch = 0;
			j++;
		}
	}
	return (1);
}

char					**ft_split(char const *s, char c)
{
	unsigned int		nb_word;
	unsigned int		i;
	char				**new;

	if (!s)
		return (NULL);
	if (!s[0])
	{
		if (!(new = (char **)malloc(sizeof(char *))))
			return (NULL);
		new[0] = 0;
		return (new);
	}
	nb_word = ft_count_sep(s, c);
	new = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!new)
		return (NULL);
	i = ft_str(s, c, new, nb_word);
	if (i == 0)
		return (NULL);
	new[nb_word] = NULL;
	return (new);
}
