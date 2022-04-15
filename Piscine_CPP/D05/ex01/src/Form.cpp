/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:59:26 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/15 11:43:09 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form() : _name("FakeForm"), _status(false), _signe(150), _execute(150)
{
}

Form::Form(std::string name, int sign, int execute) : _name(name), _status(false), _signe(sign), _execute(execute)
{
}

Form::Form(Form const & rhs) : _name(rhs._name), _status(rhs._status), _signe(rhs._signe), _execute(rhs._execute)
{
}

Form::~Form()
{
}

Form		&		Form::operator=(Form const & rhs)
{
	this->_status = rhs.getStatus();
	return *this;
}

const std::string	Form::getName()const
{
	return this->_name;
}

bool				Form::getStatus()const
{
	return this->_status;
}

int					Form::getSigne()const
{
	return this->_signe;
}

int					Form::getExecute()const
{
	return this->_execute;
}

void				Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_signe)
		this->_status = true;
	else
	{
		std::cout << this->_name;
		throw Form::GradeTooLowException();
	}
}

std::ostream	&	operator<<(std::ostream & o, Form const & rhs)
{
	if (rhs.getStatus() == false)
		o << rhs.getName() << " is no signe, the grade for sign is " << rhs.getSigne() << " and the grade for execute is " << rhs.getExecute() << "." << std::endl;
	else
		o << rhs.getName() << " is signe, the grade for sign is " << rhs.getSigne() << " and the grade for execute is " << rhs.getExecute() << "." << std::endl;
	return o;
}

