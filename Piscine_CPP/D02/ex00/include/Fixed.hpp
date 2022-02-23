/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:41:20 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/23 13:49:18 by ybrutout         ###   ########.fr       */
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
		const static int		_comma = 8;
};

#endif
