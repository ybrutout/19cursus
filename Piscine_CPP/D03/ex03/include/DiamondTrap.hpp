/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:24:31 by yannahbruto       #+#    #+#             */
/*   Updated: 2022/03/30 13:18:17 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public :

		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & diamon);
		~DiamondTrap(void);

		DiamondTrap	&	operator=(DiamondTrap const & diamon);
		void 			attack(const std::string& target);
		void			whoAmI(void);


		protected :
		void			no_hit_no_energy(void)const;

		private :
		std::string		name;
};



#endif
