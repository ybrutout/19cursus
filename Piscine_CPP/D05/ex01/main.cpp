/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/19 13:10:00 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

int		main(void)
{
	Bureaucrat	Simone(1, "Simone");
	Bureaucrat	Pierre(150, "Pierre");
	Bureaucrat	Maxime(50, "Maxime");

	Form		A52("A52", 65, 10);
	Form		B789("B789", 150, 150);
	Form		Z12("Z12", 1, 66);

	std::cout << "	-Test constructor-" << std::endl;
	std::cout << A52;
	std::cout << B789;
	std::cout << Z12;
	std::cout << std::endl << std::endl;

	std::cout << "	-Test for sign-" << std::endl;
	Pierre.signForm(A52);
	Maxime.signForm(A52);
	std::cout << std::endl;

	Pierre.signForm(B789);
	Maxime.signForm(B789);
	Simone.signForm(B789);
	std::cout << std::endl;

	std::cout << A52;
	std::cout << B789;
	std::cout << Z12;
	std::cout << std::endl;

	Pierre.signForm(Z12);
	Maxime.signForm(Z12);
	Simone.signForm(Z12);
	std::cout << std::endl;

	return (0);
}
