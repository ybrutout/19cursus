/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:27:52 by ybrutout          #+#    #+#             */
/*   Updated: 2022/05/03 11:51:00 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack <T,Container>
{
	public:
		typedef typename MutantStack::container_type::iterator			iterator;
		typedef typename MutantStack::container_type::reverse_iterator	reverse_iterator;

		MutantStack() : MutantStack<T, Container>::stack() {};
		MutantStack(const MutantStack<T, Container>& other) : MutantStack<T, Container>::stack(other) {};
		virtual ~MutantStack() {};

		iterator				begin() { return this->c.begin();}
		iterator				end() { return this->c.end();}
		reverse_iterator		rbegin() { return this->c.rbegin();}
		reverse_iterator		rend() { return this->c.rend();}

		MutantStack &operator=(MutantStack const &rhs)
		{
			this->c = rhs.c;
			return *this;
		}
};


#endif

