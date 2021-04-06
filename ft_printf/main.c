/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:48:17 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/06 16:33:29 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main()
{
	char			a;
	int				d;
	int				pos;
	int				neg;
	int				ret;
	int				ret2;
	char			*str = "hello comment ca va ? ";

	a = 'c';
	d = 11;
	pos = 2147483647;
	neg = -2147483648;
	ret = ft_printf("|%-0*.10d| |%-0*.10i| |%-0*.10x| |%-0*.10u| |%-0*.10s| |%-0*.10p| |%-0*.10X| |%-0*.10s|\n", 10, d, 10, pos, 10, neg, 10, neg, 10, str, 10, &d, 10, pos, 10, a);
	ret2 = printf(" |%*d| |%i| |%x| |%u| |%s| |%p| |%X| \n",  d, 10, pos, neg, neg, str, &d, pos);
	printf("ret = %d\n", ret);
	printf("ret2 = %d\n", ret2);
	return (0);
}
