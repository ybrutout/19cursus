/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:30:31 by ybrutout          #+#    #+#             */
/*   Updated: 2022/05/11 14:29:24 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "include/MateriaSource.hpp"
#include "include/Ice.hpp"
#include "include/Cure.hpp"
#include "include/Character.hpp"

int main()
{
	Cure			*cure_a = new Cure;
	Ice				*ice_a = new Ice;
	Character		Clothilde("Clothilde");
	Character		Micheline("Micheline");
	Character		Josiane("Josiane");
	MateriaSource	Book_one;
	MateriaSource	Book_two;

	std::cout << "	-Test Cure and Ice-" << std::endl;
	cure_a->use(Clothilde);
	ice_a->use(Micheline);
	std::cout << std::endl;

	std::cout << "	-Test Character-" << std::endl;
	Clothilde.equip(cure_a);
	Clothilde.equip(ice_a);
	Micheline.equip(cure_a);
	Josiane = Micheline;
	std::cout << "Josiane is now : " << Josiane.getName() << std::endl;
	Josiane.use(0, Micheline);
	Micheline.unequip(0);
	Josiane.use(0, Clothilde);
	std::cout << std::endl;

	Josiane = Clothilde;
	std::cout << "Josiane is now : " << Josiane.getName() << std::endl;
	for (int i = 0; i < 4; i++)
		Josiane.use(i, Micheline);
	std::cout << std::endl;

	std::cout << "	-Test MateriaSource-" << std::endl;
	Book_one.learnMateria(ice_a);
	Book_one.learnMateria(ice_a);
	Book_one.learnMateria(ice_a);
	Book_one.learnMateria(ice_a);

	Book_two.learnMateria(cure_a);
	Book_two.learnMateria(cure_a);
	Book_two.learnMateria(cure_a);
	Book_two.learnMateria(cure_a);

	AMateria	*tab[8];

	for (int i = 0; i < 8; i++)
	{
		if (i % 2)
			tab[i] = Book_one.createMateria("ice");
		else
			tab[i] = Book_two.createMateria("cure");
	}

	for (int i = 0; i < 8; i++)
		std::cout << tab[i]->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "	-Deep copy-" << std::endl;
	for (int i = 0; i < 8; i++)
		delete tab[i];
	ice_a->use(Micheline);
	cure_a->use(Clothilde);

	return (0);
}
