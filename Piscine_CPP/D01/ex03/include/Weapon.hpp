/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:30:07 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/26 08:32:13 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon{
	public:
		Weapon(std::string	type_weapon);
		~Weapon(void);

		std::string	const &	getType(void)const;
		void				setType(std::string type);

	private:
		std::string	type;
};

#endif
