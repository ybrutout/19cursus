/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:09:35 by ybrutout          #+#    #+#             */
/*   Updated: 2021/05/07 16:45:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_split_2(char	**new_s, char c, char const *s, int i)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	new_s[i] = malloc(ft_next_wrd(s, c, k) + 1);
	if (!new_s)
		return (ft_free(new_s, i));
	while (s[k] != '\0' && s[k] == c)
		k++;
	while (s[k] != '\0' && s[k] != c)
		new_s[i][j++] = s[k++];
	new_s[i][j] = '\0';
}
