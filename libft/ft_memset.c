/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:24:41 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/16 16:50:47 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *s;
	int i; 

	i = 0;
	*s = (unsigned char *)b;
	while (len > 0)
	{
		s[i] = (unsigned char) c;
		i++;
		len--;
	}
	
	return(*b);
}

int		main(void)
{
	
	return(0);
}