/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/19 12:51:47 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat 	*Albert;
	Bureaucrat		*Steve;
	Bureaucrat		*Michael;
	Bureaucrat		*Johny;
	Bureaucrat		*Bob;
	Bureaucrat		*Joseline;
	std::cout << "	-Test : Constructeur Low grade-" << std::endl;
	try
	{
		Albert = new Bureaucrat(150, "Albert");
		Steve = new Bureaucrat(100, "Steve");
		Joseline = new Bureaucrat(50, "Joseline");
		Michael = new Bureaucrat(1, "Michael");
		Johny = new Bureaucrat(151, "Johny");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "	-Test : Constructeur High grade-" << std::endl;
	try
	{
		Bob = new Bureaucrat(0, "Bob");
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
