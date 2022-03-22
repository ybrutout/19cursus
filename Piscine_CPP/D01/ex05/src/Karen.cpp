/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:33:32 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/22 11:55:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Karen.hpp"

Karen::Karen(void){
	std::cout<<"O No ! A karen has just entered your restaurant."<<std::endl;
}

Karen::~Karen(void){
	std::cout<<"O Yes! Karen leaves the restaurant !"<<std::endl;
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
	void	(Karen::*fct[4])(void)= {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	std::string	lvl[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
	{
		if (lvl[i] == level)
		{
			(this->*(fct[i]))();
			return ;
		}
	}
	std::cout<<"Karen doesn't understand what she has to do."<<std::endl;
	std::cout<<"Karen needs an argument to get you started:"<<std::endl;
	std::cout<<"	- debug"<<std::endl;
	std::cout<<"	- info"<<std::endl;
	std::cout<<"	- warnig"<<std::endl;
	std::cout<<"	- error"<<std::endl;
}
