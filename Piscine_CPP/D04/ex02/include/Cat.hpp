/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:10:26 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/05 14:51:48 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(Cat const & cat);
		virtual ~Cat();

		Cat		&		operator=(Cat const & cat);

		void			makeSound(void)const;
		Brain			*getBrain(void)const;
		std::string		getIdea(int i)const;

		void			setIdea(std::string	idea);

	private:
		Brain			*_brain;
};

#endif
