/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:41:20 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/23 12:21:48 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
	public:

		Fixed(void);
		Fixed(Fixed const & fixed);
		~Fixed(void);

		Fixed	&	operator=(Fixed const & fixed);

		int getRawBits(void)const;
		void setRawBits(int const raw);

	private:

		int		_RawBits;
		int		_comma;
};

#endif
