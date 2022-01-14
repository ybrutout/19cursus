/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:17:22 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/14 16:38:31 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{}

Contact::~Contact(void)
{}


void	Contact::add_contact(void)
{
	std::cout<<"To add a new contact we need some information."<<std::endl;
	std::cout<<"First name : ";
	std::cin>>this->_first_name;
	std::cout<<"Last name : ";
	std::cin>>this->_last_name;
	std::cout<<"Nickname : ";
	std::cin>>this->_nickname;
	std::cout<<"Phone number : ";
	std::cin>>this->_phone_number;
	std::cout<<"Darkest secret : ";
	std::cin>>this->_darkest_secret;
	std::cout<<"Contact added" <<std::endl;
}

std::string Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string		Contact::getlast_name(void){
	return(this->_last_name);
}

std::string		Contact::getnickname(void){
	return(this->_nickname);
}

std::string		Contact::getphone_nb(void){
	return(this->_phone_number);
}

std::string		Contact::getdark_secret(void){
	return(this->_darkest_secret);
}