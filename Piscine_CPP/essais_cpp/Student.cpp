/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:42:58 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/16 16:06:56 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.hpp"

Student::Student(std::string login)
{
	std::cout<<"I'm create "<<login<<std::endl;
	this->login = login;
}

Student::~Student(void)
{
	std::cout<<"I'm dead "<<this->login<<std::endl;
	return ;
}
