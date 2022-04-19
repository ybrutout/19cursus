/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/19 11:55:23 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Intern.hpp"

int		main(void)
{
	std::cout << "	-Test for array-" << std::endl;
	Intern	one;

	AForm			*folder[10];
	std::string		formfolder[5] = {"shrubbery creation", "robotomy request", "presidential pardon", "I don't want to work", "I'm on holiday"};
	std::string		tagetfolder[5] = {"Muriel", "Micheline", "Alain", "Josiane", "Nahama"};
	int				j = 0;

	for (int i = 0; i < 10; i++)
	{
		if (j == 5)
			j = 0;
		folder[i] = one.makeForm(formfolder[j], tagetfolder[j]);
		j++;
	}
	std::cout << std::endl << std::endl;

	std::cout << "	-The form Work!-" << std::endl;
	std::cout << "It's the good target" << std::endl << std::endl;
	for(j = 0; j < 10; j++)
	{
		if (folder[j])
		{
			std::cout << "The form to the index " << j << " it's a " << folder[j]->getName() << " and his target is " << folder[j]->getTarget() << std::endl;
		}
	}
	std::cout << std::endl << std::endl;

	Bureaucrat	michele(135, "la mere michele");
	Bureaucrat	philippe(1, "Philou");
	for(j = 0; j < 5; j++)
	{
		if (folder[j])
		{
			michele.signForm(*folder[j]);
			philippe.signForm(*folder[j]);
		}
	}

	for(j = 0; j < 10 ; j++)
	{
		if (folder[j])
			delete folder[j];
	}
	return (0);
}
