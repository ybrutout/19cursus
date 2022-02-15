/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:21:41 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/15 09:20:09 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void){
}

Karen::~Karen(void){
}

void	Karen::debug(void){
	std::cout<<"I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"<<std::endl;
}

void	Karen::info(void){
	std::cout<<"I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"<<std::endl;
}

void	Karen::warning(void){
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month."<<std::endl;
}

void	Karen::error(void){
	std::cout<<"This is unacceptable, I want to speak to the manager now."<<std::endl;
}

void	Karen::complain(std::string level){
	int	i;
	std::string	lvl[4] = {"debug", "info", "warning", "error"};

	i = 0;
	while (i < 4)
	{
		if (lvl[i] == level)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			this->debug();
			this->info();
			this->warning();
			this->error();
			break;
		case 1:
			this->info();
			this->warning();
			this->error();
			break;
		case 2:
			this->warning();
			this->error();
			break;
		case 3:
			this->error();
			break;
		case 4:
			std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
			break;
		default:
			break;
	}
}
