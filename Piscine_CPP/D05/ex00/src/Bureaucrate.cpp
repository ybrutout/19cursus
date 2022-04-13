/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:43:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/13 13:29:24 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrate.hpp"

Bureaucrate::Bureaucrate() : _name("no_name") , _grade(150){}

Bureaucrate::Bureaucrate(int grade, std::string name) : _name(name)
{
	if (grade > 150)
		throw Bureaucrate::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrate::GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrate::Bureaucrate(Bureaucrate const & rhs)
{
	this->_grade = rhs.getGrade();
	this->_name = rhs.getName();
}

Bureaucrate::~Bureaucrate(){}

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
		throw Bureaucrate::GradeTooHighException();
	else
		this->_grade--;
}
