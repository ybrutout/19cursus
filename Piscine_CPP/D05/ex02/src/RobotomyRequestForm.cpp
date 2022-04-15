/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:53:39 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/15 13:55:57 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotForm", "", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & rhs) : AForm("RobotForm", rhs.getTarget(), 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotForm", target, 72, 45)
{}

RobotomyRequestForm::~RobotomyRequestForm(){}

void		RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	//a faire
}

RobotomyRequestForm	&	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	(void)rhs;
	return *this;
}
