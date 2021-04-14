/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_essais.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:41:52 by mushu             #+#    #+#             */
/*   Updated: 2021/04/14 15:50:40 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int 	ret2;
	char	c;

	c = 'a';

	ret2 = printf("|%.*s|\n", -3, 0);
	printf("ret2 = %d\n", ret2);
	ret2 = printf("%32s\n", NULL);
	printf("ret2 = %d\n", ret2);
	return (0);

}
