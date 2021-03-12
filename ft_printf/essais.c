/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essais.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mushu <mushu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:41:52 by mushu             #+#    #+#             */
/*   Updated: 2021/03/09 11:56:20 by mushu            ###   ########.fr       */
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
	ret2 = printf("|%c| |%d| |%i| |%x| |%u| |%s| |%p| |%X| \n", a, d, pos, neg, neg, str, &a, pos);
	ret2 = printf("|%10c| |%010d| |%010i| |%010x| |%010u| |%10s| |%10p| |%010X| \n", a, d, pos, neg, neg, str, &a, pos);
	printf("ret2 = %d\n", ret2);
	return (0);

}