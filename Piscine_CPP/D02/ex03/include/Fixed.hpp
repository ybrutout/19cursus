/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:41:20 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/03 13:08:48 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
	public:

		Fixed(void);
		Fixed(Fixed const & fixed);
		Fixed(int const rb);
		Fixed(float const fl);
		~Fixed(void);

		Fixed	&	operator=(Fixed const & fixed);

		/*Compare operator*/

		bool		operator<(Fixed const & rhs)const;
		bool		operator>(Fixed const & rhs)const;
		bool		operator<=(Fixed const & rhs)const;
		bool		operator>=(Fixed const & rhs)const;
		bool		operator!=(Fixed const & rhs)const;
		bool		operator==(Fixed const & rhs)const;

		/*Arithmetique operator*/

		Fixed		operator+(Fixed const & rhs);
		Fixed		operator-(Fixed const & rhs);
		Fixed		operator*(Fixed const & rhs);
		Fixed		operator/(Fixed const & rhs);

		/*Increment/decrement operator*/

		Fixed		operator++(void); //Pré
		Fixed		operator++(int);
		Fixed		operator--(void);//Pré
		Fixed		operator--(int);

		/*min and max member fubction*/

		static Fixed min(Fixed &a, Fixed &b);
		static Fixed max(Fixed &a, Fixed &b);

		/*min and max member fubction with const parameters*/

		static const Fixed	min(Fixed const &a, Fixed const &b);
		static const Fixed	max(Fixed const &a, Fixed const &b);

		int 		getRawBits(void)const;
		void		setRawbits(int const rb);
		int			getComma(void)const;
		int			toInt(void)const;
		float		toFloat(void)const;

	private:

		int					_RawBits;
		const static int	_comma = 8;
};

std::ostream & operator<<(::std::ostream & o, Fixed const & rhs);

#endif
