/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:29:03 by ybrutout          #+#    #+#             */
/*   Updated: 2022/04/05 11:54:10 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit_p(10), energy_p(10), damage(0)
{
	std::cout << "The ClapTrap " << name << " is born." << std::endl;
}

ClapTrap::ClapTrap() : name("default"), hit_p(10), energy_p(10), damage(0)
{
	std::cout << "The ClapTrap is born, by default constructor." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & clap)
{
	this->name = clap.getName();
	this->hit_p = clap.getHit();
	this->energy_p = clap.getEnergy();
	this->damage = clap.getDamage();
	std::cout << "The ClapTrap " << this->name << " is born, by copy constructor." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "The ClapTrap " << name << " is destructed." << std::endl;
}

ClapTrap	&	ClapTrap::operator=(ClapTrap const & clap)
{
	std::cout << "The Claptrap " << this->name << " become " << clap.getName() << "." << std::endl;
	this->name = clap.getName();
	this->hit_p = clap.getHit();
	this->energy_p = clap.getEnergy();
	this->damage = clap.getDamage();

	return (*this);
}

void			ClapTrap::attack(const std::string& target)
{
	if (this->hit_p == 0 || this->energy_p == 0)
		return (this->no_hit_no_energy());
	std::cout << "ClapTrap " << this->getName() << " attacks " << target;
	std:: cout << ", causing " << this->getDamage() << " points of damage." << std::endl;
	this->energy_p--;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_p == 0 || this->energy_p == 0)
		return (this->no_hit_no_energy());
	std::cout << "ClapTrap " << this->getName() << " receves " << amount;
	if (amount > this->getHit())
		amount = this->getHit();
	this->hit_p = this->hit_p - amount;
	std:: cout << " points of damage. He still have " << this->getHit();
	std::cout << " hit point."<< std::endl;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_p == 0 || this->energy_p == 0)
		return (this->no_hit_no_energy());
	std::cout << "The ClapTrap " << this->getName() << " is repaired with ";
	std::cout << amount << " point more." << std::endl;
	this->hit_p = this->hit_p + amount;
	this->energy_p--;
}

std::string		ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int	ClapTrap::getHit(void) const
{
	return (this->hit_p);
}

unsigned int	ClapTrap::getEnergy(void) const
{
	return (this->energy_p);
}

unsigned int	ClapTrap::getDamage(void) const
{
	return (this->damage);
}

void			ClapTrap::no_hit_no_energy(void) const
{
	if (this->hit_p == 0)
		std::cout << "The ClapTrap " << this->getName() << " is dead." << std::endl;
	else if (this->energy_p == 0)
		std::cout << "The ClapTrap " << this->getName() << " he has no energy left." << std::endl;
}
