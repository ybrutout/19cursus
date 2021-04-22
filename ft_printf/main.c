/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:11:41 by ybrutout          #+#    #+#             */
/*   Updated: 2021/04/22 16:18:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main()
{
	char	*str = malloc(1);
	int		ret;
	int		ret2;

	/*ret = ft_printf("%2.9p\n", 1234);
	ret2 = printf("%2.9p\n", 1234);
	ret = ft_printf("|%8.13p|\n", str);
	ret2 = printf("|%8.13p|\n", str);
	ret = ft_printf("%20.9p\n", 1234);
	ret2 = printf("%20.9p\n", 1234);
	ret = ft_printf("|%20.13p|\n", str);
	ret2 = printf("|%20.13p|\n", str);
	ret = ft_printf("|%p|\n", str);
	ret2 = printf("|%p|\n", str);*/
	ret = ft_printf("|%p|\n", str);
	ret2 = printf("|%p|\n", str);
	printf("ret = %d\n", ret);
	printf("ret2 = %d\n", ret2);
}
