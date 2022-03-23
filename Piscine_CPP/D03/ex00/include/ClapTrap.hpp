/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:19:57 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/23 12:28:50 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap{
	public:

		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & clap);
		~ClapTrap(void);

		ClapTrap	&	operator=(ClapTrap const & clap);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string		getName(void)const;
		unsigned int	getHit(void)const;
		unsigned int	getEnergy(void)const;
		unsigned int	getDamage(void)const;

	private:

		void			no_energy(void)const;
		void			no_hit_p(void)const;
		std::string		name;
		unsigned int	hit_p;
		unsigned int	energy_p;
		unsigned int	damage;
};
