/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:26:03 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/24 16:33:04 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & scav);
		~FragTrap(void);

		FragTrap	&	operator=(FragTrap const & scav);

		void 			highFivesGuys(void);
		void 			attack(const std::string& target);

	protected :
		void			no_hit_no_energy(void)const;
};

#endif
