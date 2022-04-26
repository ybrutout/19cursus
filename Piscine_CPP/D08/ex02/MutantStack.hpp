/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:27:52 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/26 17:54:35 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
	private:
		/* data */
};


#endif
