/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:17:22 by ybrutout          #+#    #+#             */
/*   Updated: 2022/01/13 12:12:39 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){
	std::cout << "Contact créé" << std::endl;
	return ;
}

Contact::~Contact(void){
	//Contact::_nbcontact--;
	std::cout << "Contact détruit" << std::endl;
	return ;
}

/*Contact	*new(void){
	if (this->_nbcontact == 8)
	{
		std::cout << "Oups... The repertory is full." << std::endl;
		return ;
	}
	std::cout << "Je suis crée !" << std::endl;
	std::cout <<"First name : ";
	std::cin >> this->_first_name;
	std::cout <<"Last name : ";
	std::cin >> this->_last_name;
	std::cout <<"Nickname : ";
	std::cin >> this->_nickname;
	std::cout <<"Phone number : ";
	std::cin >> this->_phone_number;
	std::cout <<"Darkest secret : ";
	std::cin >> this->_darkest_secret;
	Contact::_nbcontact++;
	return(this);
}

std::string		getfirst_name(void)const{
	return(this->_first_name);
}

std::string		getlast_name(void)const{
	return(this->_last_name);
}

std::string		getnickname(void)const{
	return(this->_nickname);
}

std::string		getphone_nb(void)const{
	return(this->_phone_number);
}

std::string		getdark_secret(void)const{
	return(this->_darkest_secret);
}

void			setfirst_name(std::string f_n){
	this->_first_name = f_n;
}

void			setlast_name(std::string l_n){
	this->_last_name = l_n;
}

void			setnickname(std::string nn){
	this->_nickname = nn;
}

void			setphone_nb(std::string pn){
	this->_phone_number = pn;
}

void			setdark_secret(std::string ds){
	this->_darkest_secret = ds;
}*/

int		Contact::getnbcontact(void){
	return(Contact::_nbcontact);
}

int		Contact::_nbcontact = 0;
