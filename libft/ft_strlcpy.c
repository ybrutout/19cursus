/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:48:32 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/16 15:50:17 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i = i + 1;
	}

	while (size != '\0' && src[j] != '\0' && j < size)
	{
		dest[j] = src[j];
		j++; 
	}
	dest[size] = '\0'; 
	return(i);
}