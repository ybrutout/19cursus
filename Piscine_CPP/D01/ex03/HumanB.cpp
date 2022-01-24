/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:32:39 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/24 16:08:13 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	std::cout<<"A human is bord"<<std::endl;
	this->setName(name);
	std::cout<<"I am a new HumanB and my name is "<<this->getName()<<std::endl;
	this->gunPTR = NULL;
}

HumanB::~HumanB(void){
	std::cout<<"HumanB "<<this->name<<"is dead"<<std::endl;
}

void		HumanB::setName(std::string name){
	this->name = name;
	std::cout<<"New humanB is called "<<this->name<<std::endl;
}

void		HumanB::setWeapon(Weapon weapon){
	this->gunPTR = &weapon;
	std::cout<<"I received my weapon type "<<this->gunPTR->getType()<<std::endl;
}

std::string	HumanB::getName(void){
	return(this->name);
}

Weapon*		HumanB::getWeapon(void){
	if (!this->gunPTR)
		return(NULL);
	return(this->gunPTR);
}

void		HumanB::attack(void){
	if (!this->getWeapon())
		std::cout<<this->getName()<<" has no weapons"<<std::endl;
	else
		std::cout<<this->getName()<<"  attacks with his "<<this->gunPTR->getType()<<std::endl;
}
