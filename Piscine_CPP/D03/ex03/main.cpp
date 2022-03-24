/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:21:56 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/24 15:51:55 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"

int	main(void)
{
	std::cout << "------Test for constructor-----" << std::endl;
	ClapTrap	Simone("Simone");
	ClapTrap	Josiane("Josiane");
	ClapTrap	Alix;
	ScavTrap	Nicole("Nicole");
	ScavTrap	Nicole_b(Nicole);
	ScavTrap	Murielle("Murielle");
	ScavTrap	Genevieve;
	FragTrap	Jacqueline("Jacqueline");
	FragTrap	Jacqueline_b(Jacqueline);
	FragTrap	Germaine("Germaine");
	FragTrap	Therese;
	std::cout << std::endl;

	std::cout << "------Test for operator = -----" << std::endl;
	Nicole_b = Murielle;
	Jacqueline_b = Germaine;
	std::cout << std::endl;

	std::cout << "------Test for highFivesGuys -----" << std::endl;
	// Nicole.highFivesGuys();
	// Nicole_b.highFivesGuys();
	// Murielle.highFivesGuys();
	//Simone.highFivesGuys();
	//Josiane.highFivesGuys();
	Jacqueline.highFivesGuys();
	Germaine.highFivesGuys();
	std::cout << std::endl;
	
	std::cout << "------Test for guardGate -----" << std::endl;
	Nicole.guardGate();
	Nicole_b.guardGate();
	Murielle.guardGate();
	//Simone.guardGate();
	//Josiane.guardGate();
	// Jacqueline.guardGate();
	// Germaine.guardGate();
	std::cout << std::endl;

	std::cout << "------Test for attack -----" << std::endl;
	Nicole.attack("Julie");
	Nicole_b.attack("Maurisse");
	Murielle.attack("Ernestine");
	Simone.attack("Georgette");
	Josiane.attack("Michelle");
	Jacqueline.attack("Monique");
	Germaine.attack("Josette");
	std::cout << std::endl;

	std::cout << "------Test for takeDamage -----" << std::endl;
	Nicole.takeDamage(10);
	Nicole_b.takeDamage(20);
	Murielle.takeDamage(150);
	Simone.takeDamage(110);
	Josiane.takeDamage(12);
	Jacqueline.takeDamage(29);
	Germaine.takeDamage(920);
	std::cout << std::endl;

	std::cout << "------Test for beRepaired -----" << std::endl;
	Nicole.beRepaired(5);
	Nicole_b.beRepaired(20);
	Murielle.beRepaired(60);
	Simone.beRepaired(2);
	Josiane.beRepaired(12);
	Jacqueline.beRepaired(856);
	Germaine.beRepaired(2);
	std::cout << std::endl;

	std::cout << "------Test for energy -----" << std::endl;
	for (int i = 0; i < 50 ; i++)
	{
		Nicole.attack("René");
		Josiane.attack("Jeannette");
		Jacqueline.attack("Yvette");
	}
	std::cout << std::endl;

	std::cout << "------Test for destructor -----" << std::endl;
	return (0);
}
