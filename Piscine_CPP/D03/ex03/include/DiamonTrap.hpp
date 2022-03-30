/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:24:31 by yannahbruto       #+#    #+#             */
/*   Updated: 2022/03/24 16:33:33 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DIAMONTRAP_HPP
# define DIAMONTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamonTrap : public FragTrap, public ScavTrap
{
	public :

		DiamonTrap();
		DiamonTrap(std::string name);
		DiamonTrap(DiamonTrap const & diamon);
		~DiamonTrap(void);

		DiamonTrap	&	operator=(DiamonTrap const & diamon);
	
};



#endif