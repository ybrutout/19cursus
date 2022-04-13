/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:43:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/13 13:18:55 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrate.hpp"

Bureaucrate::Bureaucrate() : _name("no_name") , _grade(150)
{

}

Bureaucrate::Bureaucrate(int grade, std::string name) : _name(name)
{
	if (grade > 150)
		throw Bureaucrate::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrate::GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrate::~Bureaucrate()
{
	
}
