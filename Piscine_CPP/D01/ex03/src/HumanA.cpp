/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:53:22 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/22 10:51:11 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon & weapon) : gunREF(weapon)
{
	std::cout<<"A human is bord"<<std::endl;
	this->setName(name);
	std::cout<<"I am a new HumanA and my name is "<<this->getName()<<std::endl;
}

HumanA::~HumanA(void){
	std::cout<<"HumanA "<<this->getName()<<"is dead"<<std::endl;
}

void		HumanA::setName(std::string name){
	this->name = name;
	std::cout<<"New humanA is called "<<this->name<<std::endl;
}

void		HumanA::setWeapon(Weapon weapon){
	this->gunREF = weapon;
	std::cout<<"I received my weapon type "<<this->gunREF.getType()<<std::endl;
}

std::string	HumanA::getName(void){
	return(this->name);
}

Weapon		&HumanA::getWeapon(void){
	return(this->gunREF);
}

void		HumanA::attack(void){
	std::cout<<this->getName()<<"  attacks with his "<<this->getWeapon().getType()<<std::endl;
}
