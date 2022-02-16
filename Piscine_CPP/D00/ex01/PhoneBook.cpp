/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:58:07 by ybrutout          #+#    #+#             */
/*   Updated: 2022/02/16 13:55:10 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_nbcontact = 0;
}

PhoneBook::~PhoneBook(void)
{}

Contact	*PhoneBook::get_repertory(void)
{
	int	tmp;

	tmp = this->_nbcontact;
	this->_nbcontact++;
	return(&this->_repertory[tmp]);
}

int		PhoneBook::get_nbcontact(void)const
{
	return(this->_nbcontact);
}

void	PhoneBook::have_ten(std::string buff)
{
	if (buff.size() > 10)
		std::cout<<buff.substr(0,9)<<".";
	else if (buff.size() == 10)
		std::cout<<buff;
	else
	{
		for(size_t i = 0; i + buff.size() < 10; i++)
			std::cout<<" ";
		std::cout<<buff;
	}
}

int		PhoneBook::strtoint(const char *str)
{
	int	ret = 0;

	if (str == NULL || *str == '\0')
		return (-1);
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		ret = ret * 10 + (str[i] - '0');
	}
	return (ret);
}

int	PhoneBook::show_contact(void)
{
	Contact		contact;
	std::string	buff;
	int			index;

	if (this->_nbcontact == 0)
	{
		std::cout<<"No contact"<<std::endl;
		return (1);
	}
	std::cout<<"     index|first name| last name|  nickname"<<std::endl;
	for(int i = 0; i < this->get_nbcontact(); i++)
	{
		contact = this->_repertory[i];
		buff = i;
		std::cout<<"         "<<i<<"|";

		buff = contact.get_first_name();
		this->have_ten(buff);
		std::cout<<"|";

		buff = contact.getlast_name();
		this->have_ten(buff);
		std::cout<<"|";

		buff = contact.getnickname();
		this->have_ten(buff);
		std::cout<<std::endl;
	}
	while (1)
	{
		std::cout<<"Enter the id of the desired contact : ";
		std::getline(std::cin, buff);
		if (std::cin.eof())
		{
			std::cout<<std::endl;
			return (0);
		}
		index = this->strtoint(buff.c_str());
		if (index < 0 || index > (this->_nbcontact - 1))
			std::cout<<"Oops... The id "<<buff<<" doesn't exist."<<std::endl;
		else
		{
			contact = this->_repertory[index];
			std::cout<<"First Name : "<<contact.get_first_name()<<std::endl;
			std::cout<<"Last Name : "<<contact.getlast_name()<<std::endl;
			std::cout<<"Nickname : "<<contact.getnickname()<<std::endl;
			std::cout<<"Phone Number : "<<contact.getphone_nb()<<std::endl;
			std::cout<<"Darkest Secret : "<<contact.getdark_secret()<<std::endl;
			break;
		}
	}
	return (1);
}

