/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:00:42 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/21 13:14:59 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <stdlib.h>

class Convert
{
	public:
		Convert();
		Convert(std::string value);
		Convert(Convert const & rhs);
		~Convert();

		Convert			&		operator=(Convert const & rhs);

		int						getInt()const;
		char					getChar()const;
		float					getFloat()const;
		double					getDouble()const;

		class Bad_input : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Bad input.";
				}
		};

	private:
		char					_ch;
		int						_in;
		float					_fl;
		double					_do;
		void					sinceChar();
		void					sinceInt();
		void					sinceFloat();
		void					sinceDouble();
};

std::ostream & operator<<(std::ostream & o, Convert const & rhs);

#endif
