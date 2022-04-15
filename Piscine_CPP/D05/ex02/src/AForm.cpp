/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:59:26 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/15 16:18:36 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm() : _name("FakeAForm"), _status(false), _signe(150), _execute(150), _target("")
{
}

AForm::AForm(std::string name, std::string target, int sign, int execute) : _name(name), _status(false), _signe(sign), _execute(execute), _target(target)
{
}

AForm::AForm(AForm const & rhs) : _name(rhs._name), _status(rhs._status), _signe(rhs._signe), _execute(rhs._execute), _target(rhs._target)
{
}

AForm::~AForm()
{
}

AForm		&		AForm::operator=(AForm const & rhs)
{
	this->_status = rhs.getStatus();
	return *this;
}

const std::string	AForm::getName()const
{
	return this->_name;
}

bool				AForm::getStatus()const
{
	return this->_status;
}

int					AForm::getSigne()const
{
	return this->_signe;
}

int					AForm::getExecute()const
{
	return this->_execute;
}

const std::string	AForm::getTarget() const
{
	return this->_target;
}

void				AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_signe)
		this->_status = true;
	else
	{
		std::cout << this->_name;
		throw AForm::GradeTooLowException();
	}
}

void				AForm::execute(Bureaucrat const & executor)const
{
	if (this->_status == false)
		throw AForm::NotSignException();
	if (this->_execute < executor.getGrade())
	{
		std::cout << executor.getName();
		throw AForm::GradeTooLowException();
	}
}

std::ostream	&	operator<<(std::ostream & o, AForm const & rhs)
{
	if (rhs.getStatus() == false)
		o << rhs.getName() << " is no signe, the grade for sign is " << rhs.getSigne() << " and the grade for execute is " << rhs.getExecute() << "." << std::endl;
	else
		o << rhs.getName() << " is signe, the grade for sign is " << rhs.getSigne() << " and the grade for execute is " << rhs.getExecute() << "." << std::endl;
	return o;
}

