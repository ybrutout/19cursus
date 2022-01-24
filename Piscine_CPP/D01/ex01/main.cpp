/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:16:30 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/24 13:18:06 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int		main(void){
	Zombie* horde;

	horde = zombieHorde(3, "Thérèse");
	std::cout<<"address to pointer of zombie ==	"<<horde<<std::endl;

	delete [] horde;
	return (0);
}
