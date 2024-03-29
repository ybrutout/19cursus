/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:00:16 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/21 15:35:44 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Sample.cpp

#ifndef STUDENT_HPP
# define STUDENT_HPP

# include <iostream>

class Integer{
	public:

		Integer(int const n);
		~Integer(void);

		int        getvalue(void)const;

		Integer  & operator=(Integer const & rhs);
		Integer    operator+(Integer const & rhs) const;

	private:

		int _n;

};

std::ostream & operator<<(::std::ostream & o, Integer const & rhs);

#endif
