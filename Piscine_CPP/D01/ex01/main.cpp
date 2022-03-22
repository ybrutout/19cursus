/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:16:30 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/22 10:26:55 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/Zombie.hpp"

int		main(void){
	Zombie* horde;

	horde = zombieHorde(3, "Thérèse");
	std::cout<<"address to pointer of zombie ==	"<<horde<<std::endl;

	delete [] horde;
	return (0);
}
