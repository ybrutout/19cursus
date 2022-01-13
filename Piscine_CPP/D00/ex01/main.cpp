/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:25:13 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/13 12:16:22 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int		main(void)
{
	std::string	buff;
	PhoneBook	directory;
	std::cout <<"coucou" << std::endl;
	Contact		*contact;

	while (std::cin >> buff)
	{
		if (buff.compare("ADD") == 0)
		{
			std::cout << "ADD" << std::endl;
			contact = directory.get_repertory();
			//if (contact.getnbcontact < 8)
			//	contact[contact.getnbcontact] = contact.new();
		}
		else if (buff.compare("SEARCH") == 0)
		{
			std::cout <<"SEARCH" <<std::endl;

		}
		else if (buff.compare("EXIT") == 0)
		{
			std::cout << "je quitte" << std::endl;
			return(0);
		}
	}
	return (0);
}
