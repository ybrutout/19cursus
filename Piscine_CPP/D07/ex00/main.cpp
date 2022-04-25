/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:02:08 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/25 12:30:15 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

// int main(void)
// {
// 	int 	i = 21, j = 42;
// 	float	a = 21.21f, b = 42.42f;
// 	char	c = 'c', d = 'z';
// 	double	e = 21.2121, f = 42.4242;

// 	std::cout << "a = " << i << ", b = " << j << " and the max is " << ::max<int>(i, j) << std::endl;
// 	std::cout << "a = " << a << ", b = " << b << " and the max is " << ::max<float>(a, b) << std::endl;
// 	std::cout << "a = " << c << ", b = " << d << " and the max is " << ::max<char>(c, d) << std::endl;
// 	std::cout << "a = " << e << ", b = " << f << " and the max is " << ::max<double>(e, f) << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "a = " << i << ", b = " << j << " and the min is " << ::min<int>(i, j) << std::endl;
// 	std::cout << "a = " << a << ", b = " << b << " and the min is " << ::min<float>(a, b) << std::endl;
// 	std::cout << "a = " << c << ", b = " << d << " and the min is " << ::min<char>(c, d) << std::endl;
// 	std::cout << "a = " << e << ", b = " << f << " and the min is " << ::min<double>(e, f) << std::endl;
// 	std::cout << std::endl;

// 	::swap<int>(i, j);
// 	::swap<float>(a, b);
// 	::swap<char>(c, d);
// 	::swap<double>(e, f);

// 	std::cout << "a = " << i << ", b = " << j << std::endl;
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "a = " << c << ", b = " << d << std::endl;
// 	std::cout << "a = " << e << ", b = " << f << std::endl;
// 	std::cout << std::endl;
//	return 0;
// }

int main( void )//main of the subject
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
