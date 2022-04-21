/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:29:06 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/21 18:03:45 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{
	int i = rand() % 3;
	Base	*nw;

	switch (i)
	{
		case 0:
			nw = new A;
			std::cout << "A is born." << std::endl;
			break;
		case 1:
			nw = new B;
			std::cout << "B is born." << std::endl;
			break;
		case 2:
			nw = new C;
			std::cout << "C is born." << std::endl;
		default :
			return NULL;
	}
	return nw;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Base de type A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Base de type B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Base de type C." << std::endl;
	else
		std::cout << "I don't know this type.";
}

void identify(Base& p)
{
	try
	{
		A	&	tmp = static_cast<A>(p);
		std::cout << "Base de type A." << std::endl;
	}
	catch(std::bad_cast &e)
	{
		;
	}
	try
	{
		B	&	tmpb = static_cast<B>(p);
		std::cout << "Base de type B." << std::endl;
	}
	catch(std::bad_cast &e)
	{
		;
	}
	try
	{
		C	&	tmpc = static_cast<C>(p);
		std::cout << "Base de type C." << std::endl;
	}
	catch(std::bad_cast &e)
	{
		;
	}

}

int	main(void)
{
	Base	*test;

	test = generate();
	identify(test);
	delete test;
}
