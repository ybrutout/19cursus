/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:19:57 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/30 12:10:29 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & clap);
		~ClapTrap(void);

		ClapTrap	&	operator=(ClapTrap const & clap);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void	show_the_value(void)const;

	protected:

		std::string		name;
		unsigned int	hit_p;
		unsigned int	energy_p;
		unsigned int	damage;

		void			no_hit_no_energy(void)const;
};

#endif
