/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:29:55 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/26 08:32:37 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type_weapon){
	std::cout<<"A weapon was created"<<std::endl;
	this->setType(type_weapon);
	std::cout<<"The weapon is a "<<this->getType()<<std::endl;
}

Weapon::~Weapon(void){
	std::cout<<"The weapon " <<this->type<<" was destroyed"<<std::endl;
}

std::string const &	Weapon::getType(void)const{
	return(this->type);
}

void	Weapon::setType(std::string type){
	this->type = type;
}
