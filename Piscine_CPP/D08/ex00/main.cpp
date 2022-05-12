/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:20:44 by ybrutout          #+#    #+#             */
/*   Updated: 2022/05/03 11:55:42 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>

template <typename T>
void	push_in(T *lst, size_t size)
{
	static int nb = 0;

	for (size_t i = 0; i < size; i++, nb++)
	{
		lst->push_back(nb);
	}
}

int main(void)
{
	std::list<int>			lst;

	push_in(&lst, 10);

	std::list<int>::const_iterator          it;
	std::list<int>::const_iterator          ite = lst.end();

	for (it = lst.begin(); it != ite; ++it)
	{
		std::cout << *it << std::endl;
	}

	try
	{
		std::cout << *easyfind(lst, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
