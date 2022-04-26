/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:58:18 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/26 17:21:29 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	{
		Span	span1(5);

		try
		{
			span1.addNumber(5);
			span1.addNumber(9);
			span1.addNumber(156);
			span1.addNumber(-25);
			span1.addNumber(89);
			span1.addNumber(38);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Max span is " << span1.longestSpan() << "." << std::endl;
		std::cout << "Min span is " << span1.shortestSpan() << "." << std::endl;
	}
	std::cout << std::endl;
	{
		Span					span2(10000);
		std::vector<int>		vect;

		try
		{
			for (int i = 0; i < 10001; i++)
				vect.push_back(i);
			span2.addNumber(vect.begin(), vect.end());
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Max span is " << span2.longestSpan() << "." << std::endl;
		std::cout << "Min span is " << span2.shortestSpan() << "." << std::endl;

	}

	return 0;
}
