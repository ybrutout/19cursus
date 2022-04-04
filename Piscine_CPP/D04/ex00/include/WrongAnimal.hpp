/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:34:56 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/04 11:36:03 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const & WrongAnimal);
		~WrongAnimal();

		WrongAnimal	&			operator=(WrongAnimal const & wronganimal);

		void				makeSound(void)const;
		std::string			getType(void)const;
	protected:
		std::string		type;
};

#endif
