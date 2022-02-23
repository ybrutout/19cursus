/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:41:20 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/23 17:48:28 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math>

class Fixed{
	public:

		Fixed(void);
		Fixed(Fixed const & fixed);
		Fixed(int rb);
		Fixed(float const fl)
		~Fixed(void);

		Fixed	&	operator=(Fixed const & fixed);

		int 	getRawBits(void)const;
		void	setRawBits(int const raw);
		int		getComma(void)const;

	private:

		int		_RawBits;
		const static int		_comma = 8;
};

std::ostream & operator<<(::std::ostream & o, Integer const & rhs);

#endif
