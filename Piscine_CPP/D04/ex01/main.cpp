/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:13:12 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/04 15:44:33 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/Brain.hpp"

int		main(void) //test for the Class Brain
{
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

	return 0;
}
