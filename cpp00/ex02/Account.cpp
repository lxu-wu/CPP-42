#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;

	t::_nbAccounts++;
	t::_totalAmount += initial_deposit;
	// std::cout << t::_totalAmount << "test";

	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;

}

Account::~Account()
{
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return t::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	// std::cout << "========================++++++++++++++++++++++++++++++++++++++++++===" << t::_totalAmount << std::endl;
	return t::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return t::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return t::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	// accounts:8;total:21524;deposits:8;withdrawals:0
	t::_displayTimestamp();
	std::cout << "accounts:" << t::_nbAccounts;
	std::cout << ";total:" << t::_totalAmount;
	std::cout << ";deposits:" << t::_totalNbDeposits;
	std::cout << ";withdrawals:" << t::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	// index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;

	this->_nbDeposits++;
	t::_totalNbDeposits++;
	this->_amount += deposit;
	t::_totalAmount += deposit;

	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	// index:0;p_amount:47;withdrawal:refused
	// index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:";
	
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}

	this->_nbWithdrawals++;
	t::_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	t::_totalAmount -= withdrawal;

	std::cout << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return	this->_amount;
}

void	Account::displayStatus( void ) const
{
// index:0;amount:42;deposits:0;withdrawals:0
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	// [19920104_091532]
	struct tm	*timeinfo;
	time_t		timer;
	char			str[16];

	time(&timer);
	timeinfo = localtime(&timer);
	strftime(str, 16, "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << str << "] ";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;