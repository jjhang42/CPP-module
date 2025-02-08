/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:02:38 by jjhang            #+#    #+#             */
/*   Updated: 2024/09/21 01:30:55 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout <<"total:" << getTotalAmount() << ";";
	std::cout <<"deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:"<< getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t	timer;
	struct tm	*clock;

	timer = time(NULL);
	clock = localtime(&timer);
	std::cout << "[" << clock->tm_year + 1900;
	std::cout << std::setfill('0') \
	<< std::setw(2) << clock->tm_mon + 1 \
	<< std::setw(2) << clock->tm_mday << "_" \
	<< std::setw(2) << clock->tm_hour \
	<< std::setw(2) << clock->tm_min \
	<< std::setw(2) << clock->tm_sec << "] ";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	if (deposit > 0)
	{
		_nbDeposits++;
		_totalNbDeposits++;
	}
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	bool flag = true;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (_amount - withdrawal < 0)
		flag = false;
	std::cout << "withdrawal:";
	if (flag == false)
		std::cout << "refused";
	else
	{
		std::cout << withdrawal << ";";
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << "amount:" << _amount << ";";
		_nbWithdrawals++;
		std::cout << "nb_withdrawals:" << _nbWithdrawals;
	}
	std::cout << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (true);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
