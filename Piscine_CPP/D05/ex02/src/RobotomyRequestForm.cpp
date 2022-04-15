/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:53:39 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/15 16:20:16 by ybrutout         ###   ########.fr       */
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

void		RobotomyRequestForm::action(Bureaucrat const &executor)const
{
	this->execute(executor);
	std::cout << "*Drilling noises*" << std::endl;
	if (rand() < RAND_MAX / 2)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy on " << this->getTarget() << " has failed." << std::endl;
}

RobotomyRequestForm	&	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	(void)rhs;
	return *this;
}
