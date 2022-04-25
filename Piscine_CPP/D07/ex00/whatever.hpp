/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:57:35 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/25 12:27:09 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template <typename T>

T			max(T const &x, T const &y)
{
	return (x >= y ? x : y);
}

template <typename T>
T           min(T const &x, T const &y)
{
	return (x <= y ? x : y);
}

template <typename T>
void		swap(T &x, T &y)
{
	T	tmp = x;
	x = y;
	y = tmp;

}

#endif
