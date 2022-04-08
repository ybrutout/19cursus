/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:13:12 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/08 10:07:12 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/Brain.hpp"

int		main(void) //my test
{
	std::cout << "----Test Brain seul-----" << std::endl;
	std::cout << "	-Constructor-" << std::endl;
	Brain	first;
	Brain	second;
	Brain	first_b(first);

	std::cout << "	-Test first-" << std::endl;
	std::cout << first.getIdea(0) << std::endl;
	first.setIdea("I'm hungry");
	first.setIdea("I'll cook.");
	first.setIdea("I can cook an omellette.");
	first.setIdea("With meat.");
	first.setIdea("with mushroom.");
	first.setIdea("With chocolate!");
	for (int i = 0; i < 7; i++)
	{
		std::cout << first.getIdea(i) << std::endl;
		std::cout << first_b.getIdea(i) << std::endl;
		std::cout << second.getIdea(i) << std::endl;
		std::cout << "---------------------" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "	-Test operator-" << std::endl;
	second = first;
	for (int i = 0; i < 7; i++)
	{
		std::cout << first.getIdea(i) << std::endl;
		std::cout << first_b.getIdea(i) << std::endl;
		std::cout << second.getIdea(i) << std::endl;
		std::cout << "---------------------" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "	-Test New idea-" << std::endl;
	second.setIdea("I ate too much!");
	for (int i = 0; i < 7; i++)
	{
		std::cout << first.getIdea(i) << std::endl;
		std::cout << first_b.getIdea(i) << std::endl;
		std::cout << second.getIdea(i) << std::endl;
		std::cout << "---------------------" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "	-Test Brain with Cat and Dog-" << std::endl;
	std::cout << "	-Constructor-" << std::endl;
	Dog		Snoopy;
	Dog		Snoopy_b(Snoopy);
	Dog		Noisette;

	Cat		Felix;
	Cat		Felix_b(Felix);
	Cat		Princesse;
	std::cout << std::endl;

	std::cout << "	-SetIdea Felix-" << std::endl;
	Felix.setIdea("I'm hungry");
	Felix.setIdea("I'll cook.");
	Felix.setIdea("I can cook an omellette.");
	Felix.setIdea("With meat.");
	Felix.setIdea("with mushroom.");
	Felix.setIdea("With chocolate!");
	for (int i = 0; i < 7; i++)
	{
		std::cout << Felix.getIdea(i) << std::endl;
		std::cout << Felix_b.getIdea(i) << std::endl;
		std::cout << Princesse.getIdea(i) << std::endl;
		std::cout << "---------------------" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "	-operator = + SetIdea Princesse-" << std::endl;
	Princesse = Felix;
	Princesse.setIdea("I hate too much!");
	for (int i = 0; i < 7; i++)
	{
		std::cout << Felix.getIdea(i) << std::endl;
		std::cout << Felix_b.getIdea(i) << std::endl;
		std::cout << Princesse.getIdea(i) << std::endl;
		std::cout << "---------------------" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "	-SetIdea Snoopy-" << std::endl;
	Snoopy.setIdea("I'm hungry");
	Snoopy.setIdea("I'll cook.");
	Snoopy.setIdea("I can cook an omellette.");
	Snoopy.setIdea("With meat.");
	Snoopy.setIdea("with mushroom.");
	Snoopy.setIdea("With chocolate!");
	for (int i = 0; i < 7; i++)
	{
		std::cout << Snoopy.getIdea(i) << std::endl;
		std::cout << Snoopy_b.getIdea(i) << std::endl;
		std::cout << Noisette.getIdea(i) << std::endl;
		std::cout << "---------------------" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "	-operator = + SetIdea Noisette-" << std::endl;
	Noisette = Snoopy;
	Noisette.setIdea("I hate too much!");
	for (int i = 0; i < 7; i++)
	{
		std::cout << Snoopy.getIdea(i) << std::endl;
		std::cout << Snoopy_b.getIdea(i) << std::endl;
		std::cout << Noisette.getIdea(i) << std::endl;
		std::cout << "---------------------" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "	-Test ask in the subject-" << std::endl;
	AAnimal	*compagnie[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			compagnie[i] = new Cat();
		else
			compagnie[i] = new Dog();
	}

	for (int i = 0; i < 10; i++)
	{
		delete compagnie[i];
	}

	Dog		*Doug = new Dog();
	Dog		Milou;

	Doug->setIdea("Bonjour, je m'appelle Doug!");
	Doug->setIdea("Et je vous aime!");
	Doug->setIdea("Mon maitre et bon et intelligent.");

	Milou = *Doug;
	delete Doug;
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << Milou.getIdea(i) << std::endl;
	}

	return 0;
}

// int main()//main subject
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;
// 	return 0;
// }

