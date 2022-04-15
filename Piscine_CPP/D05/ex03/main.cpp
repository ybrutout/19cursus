/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/15 16:26:44 by ybrutout         ###   ########.fr       */
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
	PresidentialPardonForm	Presidential("Macron");

	Pierre.signForm(Shrubb);
	Simone.signForm(Shrubb);
	Pierre.executeForm(Shrubb);
	Maxime.executeForm(Shrubb);

	Simone.signForm(Robot);
	Simone.executeForm(Robot);

	Simone.signForm(Presidential);
	Simone.executeForm(Presidential);
}
