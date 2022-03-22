/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:59:07 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/22 10:27:01 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	if (N <= 0)
	{
		std::cout<<"zombies don't exist! "<<std::endl;
		return (NULL);
	}
	Zombie*	nw = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		nw[i].setname(name);
		nw[i].announced();
		if (i == 0)
			std::cout<<"address to first zombie ==	"<<&nw[0]<<std::endl;
	}
	return (nw);
}
