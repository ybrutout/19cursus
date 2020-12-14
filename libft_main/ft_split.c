/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:05:14 by ybrutout          #+#    #+#             */
/*   Updated: 2020/12/14 10:19:18 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_sep(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	count++;
	return (count);
}

/*int			main(void)
{
	int			i;
	const char	*s = "Bonjour comment ca va  ? ";

	i = ft_count_sep(s, ' ');
	printf("nb sep : %d\n", i);
	return (0);
}*/


int			main(void)
{
	char		*string = "                  olol";
	int			i;
	char		**new;

	i = 0;
	new = ft_split(string, ' ');
	printf("split : %s\n", new[i]);
	printf("split : %s\n", new[i + 1]);
	printf("split : %s\n", new[i + 2]);
	printf("split : %s\n", new[i + 3]);
	printf("split : %s\n", new[i + 4]);
	return (0);
}

int				main(void)
{
	char		*string = "olol       ";
	int			i;
	char		**new;

	i = 0;
	new = ft_split(string, ' ');
	while (new[i])
	{
		printf("split : %s\n", new[i]);
		i++;
	}
	return (0);
}

int				main(void)
{
	char		*string = "olol       ";
	int			i;
	char		**new;

	i = 0;
	new = ft_split(string, ' ');
	while (new[i])
	{
		printf("split : %s\n", new[i]);
		i++;
	}
	return (0);
}



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

int			ft_count_ch(const char *s, char c)
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

	if (!s)
		return (NULL);
	nb_word = ft_count_sep((char *)s, c);
	i = 0;
	j = 0;
	new = malloc(sizeof(char *) * nb_word);
	if (!new)
		return (NULL);
	while (s[i] && j < nb_word)
	{
		nb_ch = ft_count_ch(&s[i], c);
		if (nb_ch > 0)
		{
			new[j] = malloc(sizeof(char) * nb_ch);
			if (!new[j])
			{
				ft_free(new, j);
				return (NULL);
			}
			ft_strlcpy(new[j], &s[i], nb_ch);
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

int						main(void)
{
	char const			*string = "hello comment ils vont ? hello comment ils vont ?hello comment ils vont  hello comment ils vont ? hello comment ils vont ? hello comment ils vont ? hello comment ils vont ? hello comment ils vont ??";
	char				c;
	char				**new;
	int					i;

	c = ' ';
	i = 0;
	new = ft_split(string, c);

	while (new[i])
	{
		printf("str : %s\n", new[i]);
		i++;
	}
	return (0);
}

int						main(void)
{
	char				*string = "\0";
	char				c;
	char				**new;
	int					i;

	c = '>';
	i = 0;
	new = ft_split(string, c);

	while (new[i])
	{
		printf("str : %s\n", new[i]);
		i++;
	}
	return (0);
}

int						main(void)
{
	char				*string = "\0";
	char				c;
	char				**new;
	int					i;

	c = '>';
	i = 0;
	new = ft_split(string, c);

	while (new[i])
	{
		printf("str : %s\n", new[i]);
		i++;
	}
	return (0);
}
