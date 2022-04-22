/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:29:06 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/22 10:06:20 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{
	int i = rand() % 3;

	switch (i)
	{
		case 0:
			std::cout << "A is born." << std::endl;
			return new A;
		case 1:
			std::cout << "B is born." << std::endl;
			return new B;
		case 2:
			std::cout << "C is born." << std::endl;
			return new C;
		default :
			return NULL;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Base de type A." << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "Base de type B." << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "Base de type C." << std::endl;
}

void identify(Base& p)
{
	try
	{
		A	&	tmp = dynamic_cast<A&>(p);
		std::cout << "Base de type A." << std::endl;
		static_cast<void>(tmp);
	}
	catch(std::bad_cast &e)
	{
		;
	}
	try
	{
		B	&	tmpb = dynamic_cast<B&>(p);
		std::cout << "Base de type B." << std::endl;
		static_cast<void>(tmpb);
	}
	catch(std::bad_cast &e)
	{
		;
	}
	try
	{
		C	&	tmpc = dynamic_cast<C&>(p);
		std::cout << "Base de type C." << std::endl;
		static_cast<void>(tmpc);
	}
	catch(std::bad_cast &e)
	{
		;
	}	
}

int	main(void)
{
	for (int i = 0; i < 10; i++)
	{
		Base	*test = generate();
		identify(test);
		identify(*test);
		delete test;
	}
	return 0;
}
