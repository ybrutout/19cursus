/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:18:10 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/03 14:45:01 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Point.hpp"

int		main(void){
	float const	fl1 = 19.125f;
	float const	fl2 = 42.25f;

	Point	a;
	Point	b(fl1, fl2);
	Point	c(b);

	std::cout << "B class " << b.get_x() << " et " << b.get_y() << std::endl;
	std::cout << "C class " << c.get_x() << " et " << c.get_y() << std::endl;
	std::cout << "A class " << a.get_x() << " et " << a.get_y() << std::endl;

	Point	A1(3, 1);
	Point	A2(3, 3);
	Point	A3(3, 4);

	Point	dans(3.5f,2);
	Point	dehors(1, 1);
	Point	sur(3.5f, 1);

	bool	ret;

	ret = bsp(A1, A2, A3, dans)
	printf("%B\n", ret);

	return (0);
}
