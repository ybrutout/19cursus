/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:24:31 by yannahbruto       #+#    #+#             */
/*   Updated: 2022/03/30 13:18:17 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DIAMONTRAP_HPP
# define DIAMONTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamonTrap : public ScavTrap, public FragTrap
{
	public :

		DiamonTrap();
		DiamonTrap(std::string name);
		DiamonTrap(DiamonTrap const & diamon);
		~DiamonTrap(void);

		DiamonTrap	&	operator=(DiamonTrap const & diamon);
		void 			attack(const std::string& target);
		void			whoAmI(void);


		protected :
		void			no_hit_no_energy(void)const;

		private :
		std::string		name;
};



#endif
