/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:38:28 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/11 15:21:26 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	//std::cout << "MateriaSource constructor by default called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_tab[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const & rhs)
{
	//std::cout << "MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (rhs._tab[i])
			this->_tab[i] = rhs._tab[i]->clone();
		else
			this->_tab[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource deconstructor called." << std::endl;
	for (int i = 0; i < 4 ; i++)
	{
		if (this->_tab[i])
			delete this->_tab[i];
	}
}

MateriaSource	&	MateriaSource::operator=(MateriaSource const & rhs)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_tab[i])
			delete this->_tab[i];
		if (rhs._tab[i])
			this->_tab[i] = rhs._tab[i]->clone();
		else
			this->_tab[i] = NULL;
	}
	return *this;
}

void				MateriaSource::learnMateria(AMateria* rhs)
{
	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
			break;
		if (!this->_tab[i])
		{
			this->_tab[i] = rhs->clone();
			break;
		}
	}
}

AMateria		*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
			break;
		if (this->_tab[i]->getType() == type)
			return this->_tab[i]->clone();
	}
	return (NULL);
}
