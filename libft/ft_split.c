/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:25:54 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/25 16:49:08 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_sep(char *s, char c)
{
	int		i;
	int		count;

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
	count = count + 1;
	return (count);
}

int			ft_count_ch(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c)
	{
		i++;
	}
	if (i > 0)
		i++;
	return (i);
}

void		ft_free(char **new, int j)
{
	while (j)
	{
		free(&new[j]);
		j--;
	}
	free(new);
}

char		**ft_split(char const *s, char c)
{
	int		nb_word;
	int		i;
	int		j;
	int		nb_ch;
	char	**new;
	char	*new_s;

	if (!s)
		return(NULL);
	new_s = (char *)s;
	nb_word = ft_count_sep(new_s, c);
	i = 0;
	j = 0;
	new = malloc(sizeof(char *) * nb_word);
	if (!new)
		return (NULL);
	while (s[i] && j < nb_word)
	{
		nb_ch = ft_count_ch(&new_s[i], c);
		if (nb_ch > 0)
		{
			new[j] = malloc(sizeof(char) * nb_ch);
			if (!new[j])
			{
				ft_free(new, j);
				return (NULL);
			}
			ft_strlcpy(new[j], &new_s[i], nb_ch);
			i = i + nb_ch;
			nb_ch = 0;
			j++;
		}
		else
			i++;
	}
	new[nb_word - 1] = NULL;
	return (new);
}
