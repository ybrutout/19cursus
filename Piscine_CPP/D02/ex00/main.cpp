/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:43:45 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/23 12:38:34 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//main présent dans le sujet
/*int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
*/

int main(void){

	Fixed	a;
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(897);
	std::cout << a.getRawBits() << std::endl;

	Fixed	b(a);
	std::cout << b.getRawBits() << std::endl;


	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(50);
	std::cout << a.getRawBits() << std::endl;
	Fixed c;
	std::cout << c.getRawBits() << std::endl;
	c = a;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}
