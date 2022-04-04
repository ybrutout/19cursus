/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:33:05 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/04 10:00:48 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(Animal const & animal);
		virtual ~Animal();

		Animal	&			operator=(Animal const & animal);

		virtual void		makeSound(void)const;
		std::string			getType(void)const;
	protected:
		std::string		type;
};

#endif
