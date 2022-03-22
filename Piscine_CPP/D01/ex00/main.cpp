/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:00:02 by ybrutout          #+#    #+#             */
/*   Updated: 2022/03/22 10:21:39 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

int		main(void)
{
	Zombie*	heap = newZombie("Simone");

	randomChump("Nicole");
	delete heap;
	return (0);
}
