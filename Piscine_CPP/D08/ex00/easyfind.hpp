/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:55:32 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/26 14:04:33 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class NotFind : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "This search isn't in this container.";
		}
};

template < typename T >
typename T::iterator		easyfind(T &container, int search)
{
	typename T::iterator find = std::find(container.begin(), container.end(), search);
	if (find != container.end())
		return find;
	else
		throw NotFind();
}

#endif
