/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:25:13 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/14 13:56:49 by yannahbruto      ###   ########.fr       */
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
		std::cin >> buff;
		if (buff.compare("ADD") == 0)
		{
			if (repertory.get_nbcontact() > 7)
				std::cout <<"Oops... There are already 8 contacts. Impossible to add more."<<std::endl;
			else
			{
				contact = repertory.get_repertory();
				contact->add_contact();
			}
		}
		else if (buff.compare("SEARCH") == 0)
		{
			repertory.show_contact();
		}
		else if (buff.compare("EXIT") == 0)
			break;
	}
	return (0);
}
