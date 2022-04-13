/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:43:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/13 14:59:07 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrate.hpp"

Bureaucrate::Bureaucrate() : _name("no_name") , _grade(150){}

Bureaucrate::Bureaucrate(int grade, std::string name) : _name(name)
{
	if (grade > 150)
	{
		std::cout << this->getName() << " ";
		throw Bureaucrate::GradeTooLowException();
	}
	if (grade < 1)
	{
		std::cout << this->getName() << " ";
		throw Bureaucrate::GradeTooHighException();
	}
	else
		this->_grade = grade;
}

Bureaucrate::Bureaucrate(Bureaucrate const & rhs)
{
	this->_grade = rhs.getGrade();
	this->_name = rhs.getName();
}

Bureaucrate::~Bureaucrate(){
	std::cout << "Bureaucrate " << this->getName() << " dead." << std::endl;
}

Bureaucrate		&		Bureaucrate::operator=(Bureaucrate const & rhs)
{
	this->_grade = rhs.getGrade();
	this->_name = rhs.getName();
	return *this;
}

std::string				Bureaucrate::getName()const
{
	return this->_name;
}

int						Bureaucrate::getGrade()const
{
	return this->_grade;
}

void					Bureaucrate::incrementingGrade()
{
	if (this->_grade == 1)
	{
		std::cout << this->getName() << " ";
		throw Bureaucrate::GradeTooHighException();
	}
	else
		this->_grade--;
}

void					Bureaucrate::decrementingGrade()
{
	if (this->_grade == 150)
	{
		std::cout << this->getName() << " ";
		throw Bureaucrate::GradeTooHighException();
	}
	else
		this->_grade++;
}

std::ostream	&		operator<<(std::ostream	&	o, Bureaucrate const & rhs)
{
	o << rhs.getName() << " is a bureaucrate grade " << rhs.getGrade() << "." << std::endl;
	return o;
}
