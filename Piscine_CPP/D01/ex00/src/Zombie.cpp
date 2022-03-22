/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:17:23 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/22 10:21:19 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << name;
	this->announced();
}

Zombie::~Zombie(void){
	std::cout<<this->name<<" died"<<std::endl;
}

void	Zombie::announced(void){
	std::cout << "  BraiiiiiiinnnzzzZ..." << std::endl;
}
