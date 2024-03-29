/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:43:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/13 14:59:07 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("no_name") , _grade(150){}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name)
{
	if (grade > 150)
	{
		std::cout << this->getName() << " ";
		throw Bureaucrat::GradeTooLowException();
	}
	if (grade < 1)
	{
		std::cout << this->getName() << " ";
		throw Bureaucrat::GradeTooHighException();
	}
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs)
{
	this->_grade = rhs.getGrade();
	this->_name = rhs.getName();
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat " << this->getName() << " dead." << std::endl;
}

Bureaucrat		&		Bureaucrat::operator=(Bureaucrat const & rhs)
{
	this->_grade = rhs.getGrade();
	this->_name = rhs.getName();
	return *this;
}

std::string				Bureaucrat::getName()const
{
	return this->_name;
}

int						Bureaucrat::getGrade()const
{
	return this->_grade;
}

void					Bureaucrat::incrementingGrade()
{
	if (this->_grade == 1)
	{
		std::cout << this->getName() << " ";
		throw Bureaucrat::GradeTooHighException();
	}
	else
		this->_grade--;
}

void					Bureaucrat::decrementingGrade()
{
	if (this->_grade == 150)
	{
		std::cout << this->getName() << " ";
		throw Bureaucrat::GradeTooHighException();
	}
	else
		this->_grade++;
}

void					Bureaucrat::signForm(AForm & form)const
{
	if (form.getStatus())
	{
		std::cout << this->_name << " can't sign the form because it is already signed." << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << "form." << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << this->_name << e.what() << std::endl;
	}
}

void					Bureaucrat::executeForm(AForm const & form)const
{
	try
	{
		form.action(*this);
		std::cout << this->_name << " execute " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

std::ostream	&		operator<<(std::ostream	&	o, Bureaucrat const & rhs)
{
	o << rhs.getName() << " is a Bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return o;
}
