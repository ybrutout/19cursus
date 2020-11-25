/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:05:14 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/25 16:47:03 by ybrutout         ###   ########.fr       */
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
