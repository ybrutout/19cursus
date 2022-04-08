/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:47:50 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/08 15:37:08 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class AMateria
{
	protected:
		std::string		_type;

	public:
		AMateria(std::string const & type);
		AMateria();
		AMateria(AMateria const & rhs);
		~AMateria();

		AMateria	&			operator=(AMateria const & rhs);

		std::string const & 	getType() const;
		virtual AMateria* 		clone() const = 0;
		//virtual void 			use(ICharacter & target);
};


#endif
