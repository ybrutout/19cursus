/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:00:42 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/21 15:51:11 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <iomanip>
# include <stdlib.h>
# include <math.h>

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
		class Non_displayable : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Non displayable";
				}
		};
		class Impossible : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Impossible";
				}
		};

	private:
		char					_ch;
		int						_in;
		float					_fl;
		double					_do;
		int						_type;
};

std::ostream & operator<<(std::ostream & o, Convert const & rhs);

#endif
