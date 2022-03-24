/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:21:56 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/24 15:40:34 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Simone("Simone");
	ClapTrap	Nicole("Nicole");
	ClapTrap	third(Simone);
	ClapTrap	Alexie;

	std::cout<<std::endl;
	third = Nicole;

	std::cout<<std::endl;
	Simone.attack("Murielle");

	std::cout<<std::endl;
	Nicole.takeDamage(6);
	Simone.takeDamage(15);

	std::cout<<std::endl;
	Simone.attack("Murielle");
	Nicole.attack("Vincent");

	std::cout<<std::endl;
	Simone.beRepaired(12);
	Nicole.beRepaired(3);

	std::cout<<std::endl;

	return (0);
}
