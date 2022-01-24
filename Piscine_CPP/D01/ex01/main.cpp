/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:16:30 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/24 12:21:20 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int		main(void){
	Zombie* horde;

	horde = zombieHorde(3, "raoule");

	std::cout<<"coucou"<<std::endl;
	delete [] horde;
	return (0);
}
