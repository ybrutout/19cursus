/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:53:53 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/05 13:29:28 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain & brain)
{
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->_idea[i] = brain._idea[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor called" << std::endl;
}

Brain	&		Brain::operator=(Brain const & brain)
{
	std::cout << "Operator = called" << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->_idea[i] = brain._idea[i];
	}
	return(*this);
}

std::string		Brain::getIdea(int i)const
{
	if (this->_idea[i].empty())
		return "I don't have as many ideas.";
	return this->_idea[i];
}

void			Brain::setIdea(std::string idea)
{
	int i;
	for (i = 0; i < 100 ; i++)
	{
		if (this->_idea[i].empty())
		{
			this->_idea[i] = idea;
			break;
		}
	}
	if (i == 100)
		std::cout << "I can't have that many ideas in my little mind" << std::endl;
}

