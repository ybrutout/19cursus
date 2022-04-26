/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:09:52 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/26 17:18:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	public:
		Span();
		Span(unsigned int size);
		Span(Span const & cpy);
		~Span();

		Span	&	operator=(Span const & rhs);

		void			addNumber(int nb);
		void			addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int				shortestSpan(void)const;
		int				longestSpan(void)const;

		class FullSpan : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "The class is full.";
				}
		};
		class EmptySpan : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "The class is empty or there is only one number.";
				}
		};

	private:
		std::vector<int>		*_tab;
		unsigned int			_size;
};

#endif
