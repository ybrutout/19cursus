/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:00:40 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/19 11:33:00 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const & cpy)
{
	(void)cpy;
}

Intern::~Intern()
{}

Intern	&	Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

AForm	*	Intern::makeForm(std::string name, std::string target)
{
	AForm	*nw;
	std::string	form[3] = { "shrubbery creation", "robotomy request", "presidential pardon"};
	size_t	i;

	for (i = 0; i < 3; i++)
	{
		if (name == form[i])
			break;
	}
	switch (i)
	{
		case 0:
			nw = new ShrubberyCreationForm(target);
			break;
		case 1:
			nw = new RobotomyRequestForm(target);
			break;
		case 2:
			nw = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "The form " << name << \
			" don't exist yet. Maybe it's time to create it."\
			 << std::endl;
			return (NULL);
	}
	std::cout << "Intern create form " << name << std::endl;
	return (nw);
}

