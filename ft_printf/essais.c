/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essais.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:41:52 by mushu             #+#    #+#             */
/*   Updated: 2021/03/12 18:14:23 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int         main(void)
{
    char			a;
	int				d;
	int				pos;
	int				neg;
	int				ret2;
	char			*str = "hello comment ca va ? "; 

	a = 'a';
	d = 10;
	pos = 2147483647;
	neg = -2147483648;
	ret2 = printf("|%-10c| |%-10d| |%-10i| |%-10x| |%-10u| |%-10s| |%-10p| |%-10X| \n", a, d, pos, neg, neg, str, &a, pos);
	printf("ret2 = %d\n", ret2);
	return (0);

}