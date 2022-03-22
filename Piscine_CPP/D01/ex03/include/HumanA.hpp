/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:47:02 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/24 16:11:19 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	public:
		HumanA(std::string name,Weapon & weapon);
		~HumanA(void);

		void		attack(void);

		void		setName(std::string name);
		void		setWeapon(Weapon weapon);

		std::string	getName(void);
		Weapon&		getWeapon(void);

	private:
		std::string	name;
		Weapon&		gunREF;
};

#endif

