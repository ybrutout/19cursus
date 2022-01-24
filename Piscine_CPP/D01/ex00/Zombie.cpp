/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:17:23 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/24 11:26:01 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	this->announced();
}

Zombie::~Zombie(void){
	std::cout<<this->name<<" died"<<std::endl;
}

void	Zombie::announced(void){
	std::cout<<this->name<<"  BraiiiiiiinnnzzzZ..."<<std::endl;
}
