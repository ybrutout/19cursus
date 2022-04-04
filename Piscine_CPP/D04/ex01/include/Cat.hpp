/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:10:26 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/04 15:53:45 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const & cat);
		virtual ~Cat();

		Cat		&		operator=(Cat const & cat);

		void			makeSound(void)const;
		Brain			*getBrain(void)const;

	private:
		Brain			*_brain;
};

#endif
