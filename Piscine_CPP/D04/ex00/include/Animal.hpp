/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:33:05 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/30 16:41:47 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		void			makeSound(void);
	protected:
		std::string		type;
}

class Dog : public Animal
{
	public :
		void			makeSound(void);
}

class Cat : public Animal
{
	public:
		void			makeSound(void)
}

#endif
