/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mushu <mushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:48:17 by ybrutout          #+#    #+#             */
/*   Updated: 2021/03/05 17:37:13 by mushu            ###   ########.fr       */
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
	ret = ft_printf("%c | %c  | %c | %d | %s\n", a, b, c, d, str);
	ret2 = printf("%c | %c  | %c | %d | %s\n", a, b, c, d, str);
	printf("ret = %d\n", ret);
	printf("ret2 = %d\n", ret2);
	return (0);
}
