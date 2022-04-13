/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:13:12 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/11 16:49:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongCat.hpp"

int		main(void)
{
	std::cout << "	-Test for constructor-" << std::endl;
	Animal	Louis;
	Animal	Louis_b(Louis);
	Animal	Lucie;
	std::cout << std::endl;
	Dog		Jerome;
	Dog		Jerome_b(Jerome);
	Dog		Jeanette;
	std::cout << std::endl;
	Cat		Gilles;
	Cat		Gilles_b(Gilles);
	Cat		Cassandre;
	std::cout << std::endl << std::endl;

	std::cout << "	-Test for operator = -" << std::endl;
	Lucie = Louis;
	Jeanette = Jerome;
	Cassandre = Gilles;
	std::cout << std::endl;

	std::cout << "	-Test for makeSound() -" << std::endl;
	Lucie.makeSound();
	Jeanette.makeSound();
	Cassandre.makeSound();
	std::cout << std::endl;

	std::cout << "	-Test for deconstructor-" << std::endl;
	return (0);
}

// int main()//test subject
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	delete meta;
// 	delete j;
// 	delete i;
// 	return 0;
// }

// int main()
// {
// const WrongAnimal* meta = new WrongAnimal();
// const WrongAnimal* i = new WrongCat();
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
// meta->makeSound();
// // delete meta;
// // delete i;
// return 0;
// }
