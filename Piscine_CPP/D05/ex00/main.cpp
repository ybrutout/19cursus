/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/13 15:05:56 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrate.hpp"

int		main(void)
{
	Bureaucrate 	*Albert;
	Bureaucrate		*Steve;
	Bureaucrate		*Michael;
	Bureaucrate		*Johny;
	Bureaucrate		*Bob;
	Bureaucrate		*Joseline;
	std::cout << "	-Test : Constructeur Low grade-" << std::endl;
	try
	{
		Albert = new Bureaucrate(150, "Albert");
		Steve = new Bureaucrate(100, "Steve");
		Joseline = new Bureaucrate(50, "Joseline");
		Michael = new Bureaucrate(1, "Michael");
		Johny = new Bureaucrate(151, "Johny");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "	-Test : Constructeur High grade-" << std::endl;
	try
	{
		Bob = new Bureaucrate(0, "Bob");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "	-Test : Incrementation-" << std::endl;
	try
	{
		Steve->incrementingGrade();
		Michael->incrementingGrade();
		Joseline->incrementingGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *Steve;
	std::cout << *Joseline;
	std::cout << std::endl;


	std::cout << "	-Test : Decrementation-" << std::endl;
	try
	{
		Steve->decrementingGrade();
		Albert->decrementingGrade();
		Joseline->decrementingGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *Steve;
	std::cout << *Joseline;
	std::cout << std::endl;

}
