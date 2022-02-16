/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:17:22 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/16 14:35:20 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

int	receve_info(std::string *buff)
{
	std::getline(std::cin, *buff);
	if (std::cin.eof())
	{
		std::cout<<std::endl<<"Error : The contact has notbeen added"<<std::endl;
		return (0);
	}
	return (1);
}

int	Contact::add_contact(void)
{
	std::cout<<"To add a new contact we need some information."<<std::endl;
	std::cout<<"First name : ";
	if (!receve_info(&this->_first_name))
		return(0);
	std::cout<<"Last name : ";
	if (!receve_info(&this->_last_name))
		return(0);
	std::cout<<"Nickname : ";
	if (!receve_info(&this->_nickname))
		return(0);
	std::cout<<"Phone number : ";
	if (!receve_info(&this->_phone_number))
		return(0);
	std::cout<<"Darkest secret : ";
	if (!receve_info(&this->_darkest_secret))
		return(0);
	std::cout<<"Contact added" <<std::endl;
	return (1);
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
