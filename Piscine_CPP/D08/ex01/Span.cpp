/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:09:44 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/26 17:13:17 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size (0)
{
	this->_tab = new std::vector<int>;
}

Span::Span(unsigned int size) : _size(size)
{
	this->_tab = new std::vector<int>;
}

// Span::Span(Span const & cpy)
// {

// }

Span::~Span()
{
	delete this->_tab;
}

void		Span::addNumber(int nb)
{
	if (this->_tab->size() < this->_size)
		this->_tab->push_back(nb);
	else
		throw Span::FullSpan();
}

void		Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		if (this->_tab->size() >= this->_size)
			throw Span::FullSpan();
		this->_tab->push_back(*begin);
		begin++;
	}
}

int			Span::shortestSpan(void)const
{
	if (this->_tab->empty() || this->_tab->size() == 1)
		throw Span::EmptySpan();
	std::vector<int>::iterator	end = this->_tab->end();
	unsigned int				span = -1;

	for (std::vector<int>::iterator begin = this->_tab->begin(); begin != end; begin++)
	{
		for (std::vector<int>::iterator begin_b = begin + 1; begin_b != end; begin_b++)
		{
			if (span > static_cast<unsigned int>(*begin_b - *begin))
				span = static_cast<unsigned int>(*begin_b - *begin);
		}
	}
	return span;
}

int			Span::longestSpan(void)const
{
	if (this->_tab->empty()|| this->_tab->size() == 1)
		throw Span::EmptySpan();
	std::vector<int>::iterator	begin = this->_tab->begin();
	std::vector<int>::iterator	end = this->_tab->end();
	int							min = *std::min_element(begin, end);
	int							max = *std::max_element(begin, end);

	return (max - min);
}
