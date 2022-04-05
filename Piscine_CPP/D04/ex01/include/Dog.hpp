/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:10:28 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/05 13:24:47 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(Dog const & dog);
		virtual ~Dog();

		Dog		&		operator=(Dog const & dog);

		void			makeSound(void)const;
		Brain			*getBrain(void)const;
		std::string		getIdea(int i)const;

		void			setIdea(std::string	idea);
	private:
		Brain			*_brain;
};

#endif
