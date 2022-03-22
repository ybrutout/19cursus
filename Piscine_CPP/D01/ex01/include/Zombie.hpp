/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:00:04 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/22 10:39:04 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie{
	public:
		Zombie(void);
		~Zombie(void);
		void		setname(std::string name);
		void		announced(void);

	private:
		std::string	name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
