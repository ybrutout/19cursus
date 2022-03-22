/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:12:58 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/24 16:06:57 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	public:
		HumanB(std::string name);
		~HumanB(void);

		void		attack(void);

		void		setName(std::string name);
		void		setWeapon(Weapon weapon);

		std::string	getName(void);
		Weapon		*getWeapon(void);

	private:
		std::string	name;
		Weapon		*gunPTR;
};

#endif
