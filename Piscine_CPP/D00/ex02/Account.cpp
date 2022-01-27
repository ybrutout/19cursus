/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:20:03 by yannahbruto       #+#    #+#             */
/*   Updated: 2022/01/17 15:33:49 by yannahbruto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <cstring>

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount = Account::_totalAmount + initial_deposit;
	std::cout<< "index:"<<_accountIndex;
	std::cout<<";amount:"<<initial_deposit;
	std::cout<<";created"<<std::endl;
	return;
}

Account::~Account(void)
{
	std::cout<<"index:"<<this->_accountIndex;
	std::cout<<";amount:"<<this->_amount;
	std::cout<<";closed"<<std::endl;
	Account::_nbAccounts--;
	Account::_totalAmount--;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	return;
}

int		Account::getNbAccounts(void)
{
	return(_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return(_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	std::cout<<"accounts:"<<Account::getNbAccounts();
	std::cout<<";total:"<<Account::getTotalAmount();
	std::cout<<";deposits:"<<Account::getNbDeposits();
	std::cout<<";withdrawals:"<<Account::getNbWithdrawals();
	std::cout<<std::endl;
}

void	Account::displayStatus(void)const{
	std::cout<<"index:"<<this->_accountIndex;
	std::cout<<";amount:"<<this->_amount;
	std::cout<<";deposits:"<<this->_nbDeposits;
	std::cout<<";withdrawals:"<<this->_nbWithdrawals<<std::endl;
}

void	Account::makeDeposit(int deposit){
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout<<"index:"<<this->_accountIndex;
	std::cout<<";p_amount:"<<this->_amount;
	std::cout<<";deposit:"<<deposit;
	_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout<<";amount:"<<this->_amount;
	std::cout<<";nb_deposits:"<<this->_nbDeposits;
	std::cout<<std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	std::cout<<"index:"<<this->_accountIndex;
	std::cout<<";p_amount:"<<this->_amount<<";withdrawal:";
	if (this->_amount < withdrawal)
	{
		std::cout<<"refused"<<std::endl;
		return(0);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout<<withdrawal;
		std::cout<<";amount:"<<this->_amount;
		std::cout<<";nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
		return(1);
	}
}

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

