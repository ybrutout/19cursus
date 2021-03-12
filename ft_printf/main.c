/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:48:17 by ybrutout          #+#    #+#             */
/*   Updated: 2021/03/05 23:15:18 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main()
{
	char		a;
	char 		b;
	char 		c;
	int			d;
	int			ret;
	int			ret2;
	char		*str = "hello comment ca va ? ";

	a = 'a';
	b = 'b';
	c = 'c';
	d = 10;
	ret = ft_printf("%c | %c  | %c  | %d | %s | %p\n", a, b, c, d, str, str);
	ret2 = printf("%c | %c  | %c  | %d | %s | %p\n", a, b, c, d, str, str);
	printf("ret = %d\n", ret);
	printf("ret2 = %d\n", ret2);
	return (0);
}
