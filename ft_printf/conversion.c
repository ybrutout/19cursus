/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mushu <mushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:17:52 by mushu             #+#    #+#             */
/*   Updated: 2021/03/08 15:27:46 by mushu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long int			ft_strnbr(long int n)
{
	long int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i = i + 2;
	return (i);
}

char						*ft_itoa(int n)
{
	char					*c;
	unsigned long long int	size;
	unsigned long long int	new_n;

	new_n = n;
	size = ft_strnbr(new_n);
	c = (char *)malloc(sizeof(char) * size);
	if (!c)
		return;
	c[--size] = '\0';
	if (new_n == 0)
		c[0] = '0';
	while (new_n)
	{
		c[--size] = new_n % 10 + 48;
		new_n = new_n / 10;
	}
	return (c);
}