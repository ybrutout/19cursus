/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:33:05 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/05 14:50:02 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(AAnimal const & Aanimal);
		virtual ~AAnimal();

		AAnimal	&			operator=(AAnimal const & animal);

		virtual void		makeSound(void)const = 0;
		virtual std::string	getType(void)const = 0;
	protected:
		std::string		type;
};

#endif
