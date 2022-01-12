/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:25:13 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/12 15:58:15 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(void)
{
	std::string	buff;

	while (std::cin >> buff)
	{
		if (buff.compare("ADD") == 0)
			std::cout << "ADD" << std::endl;
		else if (buff.compare("SEARCH") == 0)
			std::cout <<"SEARCH" <<std::endl;
		else if (buff.compare("EXIT") == 0)
		{
			std::cout << "je quitte" << std::endl;
			return(0);
		}
	}
	return (0);
}
