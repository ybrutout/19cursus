/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:21:56 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/30 13:28:00 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScavTrap.hpp"
#include "include/FragTrap.hpp"
#include "include/DiamonTrap.hpp"

int	main(void)
{
	std::cout << "------Test for constructor-----" << std::endl;
	DiamonTrap	Clotilde("Clotilde");
	DiamonTrap	Clotilde_b(Clotilde);
	DiamonTrap	Paulette("Paulette");
	DiamonTrap	Madeleine;

	std::cout << std::endl;

	Clotilde.show_the_value();
	Paulette.show_the_value();
	Madeleine.show_the_value();

	std::cout <<std::endl;

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
	Clotilde_b = Paulette;
	std::cout << std::endl;

	std::cout << "------Test for highFivesGuys -----" << std::endl;
	// Nicole.highFivesGuys();
	// Nicole_b.highFivesGuys();
	// Murielle.highFivesGuys();
	//Simone.highFivesGuys();
	//Josiane.highFivesGuys();
	Jacqueline.highFivesGuys();
	Germaine.highFivesGuys();
	Clotilde.highFivesGuys();
	Paulette.highFivesGuys();
	std::cout << std::endl;

	std::cout << "------Test for guardGate -----" << std::endl;
	Nicole.guardGate();
	Nicole_b.guardGate();
	Murielle.guardGate();
	//Simone.guardGate();
	//Josiane.guardGate();
	// Jacqueline.guardGate();
	// Germaine.guardGate();
	Clotilde.guardGate();
	Paulette.guardGate();
	std::cout << std::endl;

	std::cout << "------Test for attack -----" << std::endl;
	Nicole.attack("Julie");
	Nicole_b.attack("Maurisse");
	Murielle.attack("Ernestine");
	Simone.attack("Georgette");
	Josiane.attack("Michelle");
	Jacqueline.attack("Monique");
	Germaine.attack("Josette");
	Clotilde.attack("Yvonne");
	Paulette.attack("Lucienne");
	std::cout << std::endl;

	std::cout << "------Test for takeDamage -----" << std::endl;
	Nicole.takeDamage(10);
	Nicole_b.takeDamage(20);
	Murielle.takeDamage(150);
	Simone.takeDamage(110);
	Josiane.takeDamage(12);
	Jacqueline.takeDamage(29);
	Germaine.takeDamage(920);
	Clotilde.takeDamage(28);
	Paulette.takeDamage(420);
	std::cout << std::endl;

	std::cout << "------Test for beRepaired -----" << std::endl;
	Nicole.beRepaired(5);
	Nicole_b.beRepaired(20);
	Murielle.beRepaired(60);
	Simone.beRepaired(2);
	Josiane.beRepaired(12);
	Jacqueline.beRepaired(856);
	Germaine.beRepaired(2);
	Clotilde.beRepaired(28);
	Paulette.beRepaired(420);
	std::cout << std::endl;

	std::cout << "------Test for whoAmI -----" << std::endl;
	// Nicole.whoAmI();
	// Nicole_b.whoAmI();
	// Murielle.whoAmI();
	//Simone.whoAmI();
	//Josiane.whoAmI();
	//Jacqueline.whoAmI();
	//Germaine.whoAmI();
	Clotilde.whoAmI();
	Paulette.whoAmI();
	std::cout << std::endl;



	std::cout << "------Test for energy -----" << std::endl;
	for (int i = 0; i < 100 ; i++)
	{
		Nicole.attack("René");
		Josiane.attack("Jeannette");
		Jacqueline.attack("Yvette");
		Clotilde.attack("Yvonne");
		Paulette.attack("Lucienne");
	}
	std::cout << std::endl;

	std::cout << "------Test for destructor -----" << std::endl;
	return (0);
}
