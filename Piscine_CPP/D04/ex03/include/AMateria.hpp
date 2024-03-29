/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:47:50 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/11 15:45:03 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string		_type;

	public:
		AMateria(std::string const & type);
		AMateria();
		AMateria(AMateria const & rhs);
		virtual ~AMateria();

		AMateria	&			operator=(AMateria const & rhs);

		std::string const & 	getType() const;
		virtual AMateria* 		clone() const = 0;
		virtual void 			use(ICharacter & target);
};


#endif
