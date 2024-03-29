/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:59:51 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/22 10:39:14 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(void){
	std::cout<<"A zombie is born"<<std::endl;
}

Zombie::~Zombie(void){
	std::cout<<this->name<<" died"<<std::endl;
}

void	Zombie::announced(void){
	std::cout<<this->name<<"  BraiiiiiiinnnzzzZ..."<<std::endl;
}

void	Zombie::setname(std::string name){
	this->name = name;
}
