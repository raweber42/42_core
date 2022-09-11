#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// ##---------------CONSTRUCTOR + DESTRUCTOR--------------------##

Account::Account(int initial_deposit) : _accountIndex(this->_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {

	this->_nbAccounts++; // why does that work? I thought statics can only be accessed from class level, not instance level...
	this->_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
	// std::cout << "Contact constructor called" << std::endl;
	// return ;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	// std::cout << "Contact destructor called" << std::endl;
	// return ;
}

// ##-----------------MEMBER FUNCTIONS------------------------## 

void	Account::displayAccountsInfos( void ) { // do i HAVE TO add the Account:: before the function calls?

	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";amount:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}
	
int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}


void	Account::makeDeposit( int deposit ) {
	
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (1);
}

// int		Account::checkAmount( void ) const {

// }

void	Account::displayStatus( void ) const {
	
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {

	time_t t = time(nullptr);
    tm *tm = localtime(&t);

	std::cout << "[" << (tm->tm_year + 1900);
	std::cout << std::setw(2) << std::setfill('0') << tm->tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << tm->tm_mday;
	std::cout << "_" << std::setw(2) << std::setfill('0') << tm->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << tm->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << tm->tm_sec << "]";

}
