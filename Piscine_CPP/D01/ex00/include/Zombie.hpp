/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:18:05 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/24 11:24:18 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie{
	public:
		Zombie(std::string name);
		~Zombie(void);

	private:
		void		announced(void);
		std::string	name;
};

Zombie*		newZombie( std::string name );
void 		randomChump( std::string name );

#endif
