/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/19 13:18:16 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/RobotomyRequestForm.hpp"

int		main(void)
{
	Bureaucrat	Simone(1, "Simone");
	Bureaucrat	Pierre(150, "Pierre");
	Bureaucrat	Maxime(50, "Maxime");

	ShrubberyCreationForm	Shrubb("Home");
	RobotomyRequestForm		Robot("Steve");
	PresidentialPardonForm	Presidential("Murielle");
	
	Pierre.signForm(Shrubb);
	Simone.signForm(Shrubb);
	std::cout << std::endl;

	Pierre.executeForm(Shrubb);
	Maxime.executeForm(Shrubb);
	std::cout << std::endl;

	Simone.signForm(Robot);
	Simone.executeForm(Robot);
	std::cout << std::endl;

	Simone.signForm(Presidential);
	Simone.executeForm(Presidential);
}
