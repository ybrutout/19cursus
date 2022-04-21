/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:02:23 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/21 17:18:49 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
	Data		*test = new Data("test");
	uintptr_t	tmp;

	std::cout << test << std::endl;
	std::cout << "The name of data is " << test->getName() << "." << std::endl;
	tmp = serialize(test);
	std::cout << &tmp << std::endl;
	test = deserialize(tmp);
	std::cout << test << std::endl;
	std::cout << "The name of data is " << test->getName() << "." << std::endl;
	return 0;
}
