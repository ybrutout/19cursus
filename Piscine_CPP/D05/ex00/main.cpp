/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:36 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/13 13:18:12 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrate.hpp"

int		main(void)
{
	try
	{
		Bureaucrate 	Bureaucrate1(0, "albert");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
