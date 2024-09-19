/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:30:32 by sbartoul          #+#    #+#             */
/*   Updated: 2024/09/19 10:21:02 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
	time_t		curr_time; //current time in second since jan 1, 1970
	struct tm	*tm_local;

	time(&curr_time); //this call retreives the current time and stores it in currt_time.
	tm_local = localtime(&curr_time); //convert to human readable form broken into year, month, day, hour, minute and second. returns a tm struct
	std::cout << "[" << (tm_local->tm_year + 1900);
	if (tm_local->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << (tm_local->tm_mon + 1); //month
	if (tm_local->tm_mday < 10)
		std::cout << "0";
	std::cout << tm_local->tm_mday << "_"; //day and print _ to print time.
	if (tm_local->tm_hour < 10)
		std::cout << "0";
	std::cout << (tm_local->tm_hour);
	if (tm_local->tm_min < 10)
		std::cout << "0";
	std::cout << (tm_local->tm_min);
	if (tm_local->tm_sec < 10)
		std::cout << "0";
	std::cout << (tm_local->tm_sec) << "] ";
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawls:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount;

	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "withdrawl:" << "refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawl:" <<withdrawal << ";";
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawls:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount() const
{
	return (this->_amount);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawls:" << this->_nbWithdrawals << std::endl;
}
