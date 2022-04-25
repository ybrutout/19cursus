/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:29:45 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/25 14:16:58 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"


int main (void)
{
	int				i[10] = {1, 56, 789, 2147483647, -2147483648, -478, 4356541, -489456, 0, 42};
	std::string		str[4] = {"Josiane", "Micheline", "Murielle", "Myriam"};
	float			fl[4] = {89.89f, 456465, 5, -1164.23f};

	iter(i, 10, display<int>);
	std::cout << std::endl;

	iter(str, 4, display<std::string>);
	std::cout << std::endl;

	iter(fl, 4, display<float>);

	return 0;
}
