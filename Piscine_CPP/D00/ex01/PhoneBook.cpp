/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:58:07 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/13 12:20:11 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	std::cout <<"PhoneBook créé" << std::endl;
	_nbcontact = 0;
	return;
}

PhoneBook::~PhoneBook(void){
	std::cout <<"PhoneBook Détruit" << std::endl;
	return;
}

Contact	*PhoneBook::get_repertory(void){
	return(&this->_repertory[this->_nbcontact]);
}
