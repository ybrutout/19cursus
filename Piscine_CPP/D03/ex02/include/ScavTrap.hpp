/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:51:35 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/23 16:30:29 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & scav);
		~ScavTrap(void);

		ScavTrap	&	operator=(ScavTrap const & scav);

		void			guardGate(void);
		void 			attack(const std::string& target);

	protected :
		void			no_hit_no_energy(void)const;
};

#endif
