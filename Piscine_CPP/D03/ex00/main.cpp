/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:21:56 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/23 12:31:50 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Simone("Simone");
	ClapTrap	Nicole("Nicole");
	ClapTrap	third(Simone);

	third = Nicole;
	Simone.attack("Murielle");
	Nicole.takeDamage(6);
	Simone.takeDamage(15);
	Simone.attack("Murielle");

	return (0);
}
