/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:29:30 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/25 12:53:45 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void		iter(T *tab, size_t size, void (*f)(const T&))
{
	for (size_t i = 0; i < size; i++)
		(*f)(tab[i]);
}

template<typename T>
void	display(T const &view)
{
	std::cout << view << std::endl;
}

#endif
