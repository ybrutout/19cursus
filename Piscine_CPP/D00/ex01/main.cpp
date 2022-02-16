/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:25:13 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/16 13:53:50 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int		main(void)
{
	std::string	buff;
	PhoneBook	repertory;
	Contact		*contact;

	while (1)
	{
		std::cout<<"Please enter the commands 'ADD', 'SEARCH' or 'EXIT': "<<std::endl;
		std::getline(std::cin, buff);
		if (std::cin.eof())
			break;
		else if (buff == "ADD")
		{
			if (repertory.get_nbcontact() > 7)
				std::cout <<"Oops... There are already 8 contacts. Impossible to add more."<<std::endl;
			else
			{
				contact = repertory.get_repertory();
				if (!(contact->add_contact()))
					break;
			}
		}
		else if (buff == "SEARCH")
		{
			if (!repertory.show_contact())
				break;
		}
		else if (buff == "EXIT")
			break;
	}
	std::cout<<"The programm closes"<<std::endl;
	return (0);
}
