/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:48:17 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/14 15:56:54 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main()
{
	char			a;
	//int				d;
	//int				pos;
	//int				neg;
	int				ret;
	int				ret2;
	//char			*str = "hello comment ca va ? ";

	a = 'd';
	//d = 11;
	//pos = 2147483647;
	//neg = -2147483648;
	ret = ft_printf("%.03s\n", NULL);
	ret2 = printf("%.03s\n", NULL);
	printf("ret = %d\n", ret);
	printf("ret2 = %d\n", ret2);
	return (0);
}
