/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:33:04 by svkhacha          #+#    #+#             */
/*   Updated: 2023/04/10 20:33:48 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "./Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() {return _nbAccounts;}
int Account::getNbDeposits() {return _totalNbDeposits;}
int Account::getNbWithdrawals() {return _totalNbWithdrawals;}
int Account::getTotalAmount() {return _totalAmount;}

void    Account::_displayTimestamp()
{
    time_t  current_time = time(NULL);
    tm*     time = std::localtime(&current_time);
    std::cout<<"["<<time->tm_year + 1900;
    std::cout<<std::setw(2)<<std::setfill('0')<<time->tm_mon + 1;
    std::cout<<std::setw(2)<<std::setfill('0')<<time->tm_mday<<"_";
    std::cout<<std::setw(2)<<std::setfill('0')<<time->tm_hour;
    std::cout<<std::setw(2)<<std::setfill('0')<<time->tm_min;
    std::cout<<std::setw(2)<<std::setfill('0')<<time->tm_sec<<"]";
}

Account::Account(int initial_deposit)
{
    this->_nbAccounts++;
    this->_accountIndex = this->_nbAccounts - 1;
    this->_amount = initial_deposit;
    this->_totalAmount += this->_amount;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";";
    std::cout<<"amount:"<<this->_amount<<";created"<<std::endl;
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout<<"accounts:"<<getNbAccounts()<<";";
    std::cout<<"total:"<<getTotalAmount()<<";";
    std::cout<<"deposits:"<<getNbDeposits()<<";";
    std::cout<<"withdrawals:"<<getNbWithdrawals()<<std::endl;
}

void    Account::displayStatus() const
{
    this->_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";";
    std::cout<<"amount:"<<this->_amount<<";";
    std::cout<<"deposits:"<<this->_nbDeposits<<";";
    std::cout<<"withdrawals:"<<this->_nbWithdrawals<<std::endl;
}

int Account::checkAmount() const {return this->_amount;}

void    Account::makeDeposit(int deposit)
{   
    this->_displayTimestamp();
    this->_totalAmount += deposit;
    this->_totalNbDeposits++;
    std::cout<<"index:"<<this->_accountIndex<<";";
    std::cout<<"p_amount:"<<this->_amount<<";"<<std::flush;
    this->_amount += deposit;
    std::cout<<"deposit:"<<deposit<<";";
    std::cout<<"amount:"<<this->_amount<<";"<<std::flush;
    this->_nbDeposits++;
    std::cout<<"nb_deposits:"<<this->_nbDeposits<<std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    this->_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";";
    std::cout<<"p_amount:"<<this->_amount<<";";
    std::cout<<"whithdrawal:"<<std::flush;
    if (withdrawal > this->checkAmount())
    {
        std::cout<<"refused"<<std::endl;
        return false;
    }
    std::cout<<withdrawal<<";"<<std::flush;
    this->_nbWithdrawals ++;
    this->_totalNbWithdrawals++;
    this->_amount -= withdrawal;
    this->_totalAmount-= withdrawal;
    std::cout<<"amount:"<<this->_amount<<";";
    std::cout<<"nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
    return true;
}

Account::~Account()
{
    this->_nbAccounts--;
    this->_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";";
    std::cout<<"amount:"<<this->_amount<<";closed"<<std::endl;
}
