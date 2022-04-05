/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:13:12 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/05 10:57:30 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/Brain.hpp"

int		main(void) //my test
{
	std::cout << "	-Test Brain seul-" << std::endl;
	Brain first;

	std::cout << first.getIdea(0) << std::endl;
	first.setIdea("I'm hungry");
	first.setIdea("I'll cook.");
	first.setIdea("I can cook an omellette.");
	first.setIdea("With meat.");
	first.setIdea("with mushroom.");
	first.setIdea("With chocolate!");
	for (int i = 0; i < 7; i++)
		std::cout << first.getIdea(i) << std::endl;
	std::cout << std::endl;

	std::cout << "	-Test Brain with Cat and Dog-" << std::endl;
	Dog		Snoopy;
	Dog		Snoopy_b(Snoopy);
	Dog		Noisette;

	Cat		Felix;
	Cat		Felix_b(Felix);
	Cat		Princesse;

	
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

int		main(void)
{

}
