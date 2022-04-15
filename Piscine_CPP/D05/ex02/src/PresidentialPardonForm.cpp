/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:56:30 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/15 13:57:22 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialForm", "", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rhs) : AForm("PresidentialForm", rhs.getTarget(), 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialForm", target, 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm(){}

void		PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	//a faire
}

PresidentialPardonForm	&	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	(void)rhs;
	return *this;
}
