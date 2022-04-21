/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:52:11 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/21 17:13:41 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _name("default") {}

Data::Data(Data const & cpy) : _name(cpy._name) {}

Data::Data(std::string name) : _name(name) {}

Data::~Data() {}

Data		&	Data::operator=(Data const & rhs)
{
	this->_name = rhs._name;
	return *this;
}

std::string		Data::getName()const
{
	return this->_name;
}

uintptr_t		serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data		*	deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
