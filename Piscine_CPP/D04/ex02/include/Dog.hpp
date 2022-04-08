/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:10:28 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/08 10:04:04 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public :
		Dog();
		Dog(Dog const & dog);
		virtual ~Dog();

		Dog		&		operator=(Dog const & dog);

		void			makeSound(void)const;
		Brain			*getBrain(void)const;
		std::string		getIdea(int i)const;
		std::string		getType(void)const;

		void			setIdea(std::string	idea);
	private:
		Brain			*_brain;
};

#endif
