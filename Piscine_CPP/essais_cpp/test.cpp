/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:51:19 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/21 15:34:34 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.hpp"

int        main(void)
{
	Integer       x( 30 );
	Integer       y( 10 );
	Integer       z( 0 );

	std::cout << "Value of x : " << x << std::endl;
	std::cout << "Value of y : " << y << std::endl;
	y = Integer (12);
	std::cout << "Value of y : " << y << std::endl;

	std::cout << "Value of z : " << z << std::endl;
	z = x + y;
	std::cout << "Value of z : " << z << std::endl;

	return (0);
}
