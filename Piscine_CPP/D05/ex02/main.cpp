/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/15 11:50:25 by ybrutout         ###   ########.fr       */
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

	std::cout << A52.getName() << " status is " << A52.getStatus() << "." << std::endl;
	std::cout << B789.getName() << " status is " << B789.getStatus() << "." << std::endl;
	std::cout << Z12.getName() << " status is " << Z12.getStatus() << "." << std::endl;

	Pierre.signForm(A52);
	Maxime.signForm(A52);

	Pierre.signForm(B789);
	Maxime.signForm(B789);
	Simone.signForm(B789);

	std::cout << A52.getName() << " status is " << A52.getStatus() << "." << std::endl;
	std::cout << B789.getName() << " status is " << B789.getStatus() << "." << std::endl;
	std::cout << Z12.getName() << " status is " << Z12.getStatus() << "." << std::endl;

	Pierre.signForm(Z12);
	Maxime.signForm(Z12);
	Simone.signForm(Z12);

}
