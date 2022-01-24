/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:25:11 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/24 14:23:22 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";

	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout<<"str address :		"<<&str<<std::endl;
	std::cout<<"stringPTR =		"<<stringPTR<<std::endl;
	std::cout<<"stringREF =		"<<&stringREF<<std::endl;

	std::cout<<"stringPTR = 		"<<*stringPTR<<std::endl;
	std::cout<<"stringREF =		"<<stringREF<<std::endl;
	return (0);
}
