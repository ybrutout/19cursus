/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:18:10 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/22 13:55:40 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Point.hpp"

int		main(void){
	// float const	fl1 = 19.125f;
	// float const	fl2 = 42.25f;

	// Point	a;
	// Point	b(fl1, fl2);
	// Point	c(b);

	// std::cout << "B class (" << b.get_x() << "," << b.get_y() << ")" << std::endl;
	// std::cout << "C class (" << c.get_x() << "," << c.get_y() << ")" << std::endl;
	// std::cout << "A class (" << a.get_x() << "," << a.get_y() << ")" << std::endl;

	Point	A1(10, 7);
	Point	A2(3.5f, 3);
	Point	A3(3.5f, 12.534f);

	std::cout << "A1 class (" << A1.get_x() << "," << A1.get_y() << ")" << std::endl;
	std::cout << "A2 class (" << A2.get_x() << "," << A2.get_y() << ")" << std::endl;
	std::cout << "A3 class (" << A3.get_x() << "," << A3.get_y() << ")" << std::endl << std::endl;

	Point	in_triangle(5,5.26f);
	Point	out_triangle(1, 1);
	Point	on_triangle(3.5f, 6);

	std::cout << "in_triangle class (" << in_triangle.get_x() << "," << in_triangle.get_y() << ")" << std::endl;
	std::cout << "out_triangle class (" << out_triangle.get_x() << "," << out_triangle.get_y() << ")" << std::endl;
	std::cout << "on_triangle class (" << on_triangle.get_x() << "," << on_triangle.get_y() << ")" << std::endl << std::endl;

	bool	ret;

	ret = bsp(A1, A2, A3, in_triangle);
	std::cout << "in triangle " << ret << std::endl;
	ret = bsp(A1, A2, A3, out_triangle);
	std::cout << "out triangle " << ret << std::endl;
	ret = bsp(A1, A2, A3, on_triangle);
	std::cout << "on triangle " << ret << std::endl;

	return (0);
}
