/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:59:50 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/15 14:26:08 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", "", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & rhs) : AForm("ShrubberyForm", rhs.getTarget(), 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", target, 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void		ShrubberyCreationForm::action(Bureaucrat const &executor)
{
	std::ofstream	myfile(this->getTarget() + "_shubbery");
}

ShrubberyCreationForm	&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	(void)rhs;
	return *this;
}





