/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:29:47 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/25 16:40:35 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	std::cout << "	-Integer Test-" << std::endl;
	Array<int>		I(5);

	try
	{
		for (int i = 0; i < 6; i++)
		{
			int tmp = rand();
			I[i] = tmp;
			std::cout << "Random to index " << i << " is " << tmp << "." << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		try
		{
			std::cout << "index = " << i << " nb == " << I[i] << "." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "	-String Test-" << std::endl;
	Array<std::string>		Name(5);

	try
	{
		Name[0] = "Josiane";
		Name[1] = "Murielle";
		Name[2] = "Sophie";
		Name[3] = "Jacqueline";
		Name[4] = "Louison";
		Name[5] = "Nahama";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for (int i = 0; i < 6; i++)
	{
		try
		{
			std::cout << "index = " << i << " nb == " << Name[i] << "." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	Array<int>	vide;

	std::cout << vide.size() << std::endl;

	return 0;
}
