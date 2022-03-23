/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:21:56 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/23 16:07:43 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScavTrap.hpp"

int	main(void)
{
	std::cout << "------Test for constructor-----" << std::endl;
	ClapTrap	Simone("Simone");
	ClapTrap	Josiane("Josiane");
	ScavTrap	Nicole("Nicole");
	ScavTrap	Nicole_b(Nicole);
	ScavTrap	Murielle("Murielle");
	std::cout << std::endl;

	std::cout << "------Test for operator = -----" << std::endl;
	Nicole_b = Murielle;
	std::cout << std::endl;

	std::cout << "------Test for guardGate -----" << std::endl;
	Nicole.guardGate();
	Nicole_b.guardGate();
	Murielle.guardGate();
	//Simone.guardGate();
	//Josiane.guardGate();
	std::cout << std::endl;

	std::cout << "------Test for attack -----" << std::endl;
	Nicole.attack("Julie");
	Nicole_b.attack("Maurisse");
	Murielle.attack("Ernestine");
	Simone.attack("Georgette");
	Josiane.attack("Michelle");
	std::cout << std::endl;

	std::cout << "------Test for takeDamage -----" << std::endl;
	Nicole.takeDamage(10);
	Nicole_b.takeDamage(20);
	Murielle.takeDamage(150);
	Simone.takeDamage(110);
	Josiane.takeDamage(12);
	std::cout << std::endl;

	std::cout << "------Test for beRepaired -----" << std::endl;
	Nicole.beRepaired(5);
	Nicole_b.beRepaired(20);
	Murielle.beRepaired(60);
	Simone.beRepaired(2);
	Josiane.beRepaired(12);
	std::cout << std::endl;

	std::cout << "------Test for energy -----" << std::endl;
	for (int i = 0; i < 50 ; i++)
	{
		Nicole.attack("René");
		Josiane.attack("Jeannette");
	}
	std::cout << std::endl;
	
	std::cout << "------Test for destructor -----" << std::endl;
	return (0);
}
