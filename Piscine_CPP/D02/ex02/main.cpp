/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:18:10 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/03 11:33:04 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./include/Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( 10 );
	Fixed bb( 10 );
	Fixed c( 42.42f );
	Fixed d( b );

	//test for the comparisson operator <
	std::cout << std::endl << "Oparator <" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	if (b < c)
		std::cout << "Yes !" << std::endl;
	else
		std::cout <<"Oh no!" << std::endl;
	if (c < b)
		std::cout <<"Oh no!" << std::endl;
	else
		std::cout << "Yes !" << std::endl;
	if (b < bb)
		std::cout <<"Oh no!" << std::endl;
	else
		std::cout << "Yes !" << std::endl;

	//test for the comparisson operator <=
	std::cout << std::endl << "Oparator <=" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;

	if (b <= c)
		std::cout << "Yes !" << std::endl;
	else
		std::cout <<"Oh no!" << std::endl;
	if (c <= b)
		std::cout <<"Oh no!" << std::endl;
	else
		std::cout << "Yes !" << std::endl;
	if (b <= bb)
		std::cout << "Yes !" << std::endl;
	else
		std::cout <<"Oh no!" << std::endl;

	//test for the comparisson operator <
	b = c;
	c = bb;
	std::cout << std::endl << "Oparator >" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;

	if (b > c)
		std::cout << "Yes !" << std::endl;
	else
		std::cout <<"Oh no!" << std::endl;
	if (c > b)
		std::cout <<"Oh no!" << std::endl;
	else
		std::cout << "Yes !" << std::endl;
	if (c > bb)
		std::cout <<"Oh no!" << std::endl;
	else
		std::cout << "Yes !" << std::endl;

	//test for the comparisson operator >=
	std::cout << std::endl << "Oparator >=" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;

	if (b >= c)
		std::cout << "Yes !" << std::endl;
	else
		std::cout <<"Oh no!" << std::endl;
	if (c >= b)
		std::cout <<"Oh no!" << std::endl;
	else
		std::cout << "Yes !" << std::endl;
	if (c >= bb)
		std::cout << "Yes !" << std::endl;
	else
		std::cout <<"Oh no!" << std::endl;

	//test for the comparisson operator ==
	std::cout << std::endl << "Oparator ==" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	if (b == c)
		std::cout <<"Oh no!" << std::endl;
	else
		std::cout << "Yes !" << std::endl;
	if (c == b)
		std::cout <<"Oh no!" << std::endl;
	else
		std::cout << "Yes !" << std::endl;
	if (c == bb)
		std::cout << "Yes !" << std::endl;
	else
		std::cout <<"Oh no!" << std::endl;

	//test for the comparisson operator !=
	std::cout << std::endl << "Oparator !=" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	if (b != c)
		std::cout << "Yes !" << std::endl;
	else
		std::cout <<"Oh no!" << std::endl;
	if (c != b)
		std::cout << "Yes !" << std::endl;
	else
		std::cout <<"Oh no!" << std::endl;
	if (c != bb)
		std::cout <<"Oh no!" << std::endl;
	else
		std::cout << "Yes !" << std::endl;

	//test for the Arithmetique operator +
	std::cout << std::endl << "Oparator +" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	b = b + c;
	std::cout << "b == " << b << " and c == " << c << std::endl;

	//test for the Arithmetique operator -
	std::cout << std::endl << "Oparator -" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	b = (b - c);
	std::cout << "b == " << b << " and c == " << c << std::endl;

	//test for the Arithmetique operator *
	b = (Fixed(5));
	std::cout << std::endl << "Oparator *" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	b = (b * c);
	std::cout << "b == " << b << " and c == " << c << std::endl;

	//test for the Arithmetique operator /
	std::cout << std::endl << "Oparator /" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	b = (b / c);
	std::cout << "b == " << b << " and c == " << c << std::endl;

	//test for the Increment operator ++ pré
	b = 42.42f;
	std::cout << std::endl << "Oparator ++ pré" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	++b;
	++c;
	std::cout << "b == " << b << " and c == " << c << std::endl;

	//test for the Decrement operator -- pré
	std::cout << std::endl << "Oparator -- pré" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	--b;
	--c;
	std::cout << "b == " << b << " and c == " << c << std::endl;

	//test for the Increment operator ++ post
	b = 42.42f;
	std::cout << std::endl << "Oparator ++ post" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	b++;
	c++;
	std::cout << "b == " << b << " and c == " << c << std::endl;

	//test for the Decrement operator -- post
	std::cout << std::endl << "Oparator -- post" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	b--;
	c--;
	std::cout << "b == " << b << " and c == " << c << std::endl;

	//test for static min no const
	std::cout << std::endl << "static min no const" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	std::cout <<"min non const est : " << Fixed::min(b, c) << std::endl;

	//test for static min no const
	std::cout << std::endl << "static max no const" << std::endl;
	std::cout << "b == " << b << " and c == " << c << std::endl;
	std::cout <<"max non const est : " << Fixed::max(b, c) << std::endl;

	//test for static min const
	Fixed const e(42.4219f);
	Fixed const f(c);
	std::cout << std::endl << "static min const" << std::endl;
	std::cout << "e == " << e << " and f == " << f << std::endl;
	std::cout <<"min non const est : " << Fixed::min(e, f) << std::endl;

	//test for static max const
	std::cout << std::endl << "static max const" << std::endl;
	std::cout << "e == " << e << " and f == " << f << std::endl;
	std::cout <<"max non const est : " << Fixed::max(e, f) << std::endl;

	return 0;
}

/*main du sujet*/

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }
