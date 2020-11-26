/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essais.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:33:24 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/26 14:40:48 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	char	**ft_freemysplit(unsigned int j, char **split)
{
	while (j != 0)
		free(split[--j]);
	free(split);
	return (NULL);
}

static	char	**ft_protect(void)
{
	char	**str;

	str = malloc(sizeof(char *));
	if (str == NULL)
		return (0);
	str[0] = 0;
	return (str);
}

static int		ft_words_count(char const *str, char c)
{
	int		i;
	int		wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			wc++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (wc);
}

static char		*ft_add_word(char const *str, char c)
{
	int		i;
	char	*lstr;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	lstr = malloc(sizeof(char) * i);
	if (lstr == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		lstr[i] = str[i];
		i++;
	}
	lstr[i] = '\0';
	return (lstr);
}

char			**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (ft_strlen(str) == 0)
		return (ft_protect());
	if (!(split = malloc(sizeof(char *) * (ft_words_count(str, c) + 1))))
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			if (!(split[j] = ft_add_word(&str[i], c)))
				return (ft_freemysplit(--j, split));
			j++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	split[j] = 0;
	return (split);
}

int						main(void)
{
	char				*string = "hello>comment>ca>va>?";
	char				c;
	char				**new;
	int					i;

	c = 62;
	i = 0;
	new = ft_split(string, c);

	while (new[i])
	{
		printf("str : %s\n", new[i]);
		i++;
	}
	return (0);
}
