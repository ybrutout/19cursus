/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:18:10 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/30 09:06:54 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./include/Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl;

	std::cout << "a is " << a.toFloat() << " as Float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as Float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as Float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as Float" << std::endl;

	std::cout << std::endl;

	return 0;
}
