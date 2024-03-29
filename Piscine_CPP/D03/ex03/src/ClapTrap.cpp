/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:29:03 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/05 12:04:22 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit_p(10), energy_p(10), damage(0)
{
	std::cout << "ClapTrap of " << name;
	std::cout << " is born." << std::endl;

	//this->show_the_value();
}

ClapTrap::ClapTrap() : name("default"), hit_p(100), energy_p(50), damage(20)
{
	std::cout << "The ClapTrap is born, by default constructor." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & clap)
{
	this->name = clap.name;
	this->hit_p = clap.hit_p;
	this->energy_p = clap.energy_p;
	this->damage = clap.damage;
	std::cout << "ClapTrap constructor by copy called." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap of " << this->name;
	std::cout << " deconstructor called." << std::endl;
}

ClapTrap	&	ClapTrap::operator=(ClapTrap const & clap)
{
	std::cout << "The Claptrap " << this->name << " become " << clap.name << "." << std::endl;
	this->name = clap.name;
	this->hit_p = clap.hit_p;
	this->energy_p = clap.energy_p;
	this->damage = clap.damage;

	return (*this);
}

void			ClapTrap::attack(const std::string& target)
{
	if (this->hit_p == 0 || this->energy_p == 0)
		return (this->no_hit_no_energy());
	std::cout << "ClapTrap " << this->name << " attacks " << target;
	std:: cout << ", causing " << this->damage << " points of damage." << std::endl;
	this->energy_p--;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_p == 0 || this->energy_p == 0)
		return (this->no_hit_no_energy());
	std::cout << "ClapTrap " << this->name << " receves " << amount;
	if (amount > this->hit_p)
		amount = this->hit_p;
	this->hit_p = this->hit_p - amount;
	std:: cout << " points of damage. He still have " << this->hit_p;
	std::cout << " hit point."<< std::endl;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_p == 0 || this->energy_p == 0)
		return (this->no_hit_no_energy());
	std::cout << "The ClapTrap " << this->name << " is repaired with ";
	std::cout << amount << " point more." << std::endl;
	this->hit_p = this->hit_p + amount;
	this->energy_p--;
}

void			ClapTrap::no_hit_no_energy(void) const
{
	if (this->hit_p == 0)
		std::cout << "The ClapTrap " << this->name << " is dead." << std::endl;
	else if (this->energy_p == 0)
		std::cout << "The ClapTrap " << this->name << " he has no energy left." << std::endl;
}


void			ClapTrap::show_the_value(void)const
{
	std::cout << this->name << " value :" << std::endl;
	std::cout << "Hit point : " << this->hit_p << std::endl;
	std::cout << "Energy point : " << this->energy_p<< std::endl;
	std::cout << "damage : " << this->damage << std::endl;
}
