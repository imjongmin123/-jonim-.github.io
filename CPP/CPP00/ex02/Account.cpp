#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), 
_nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
	<< "amountt:" << _amount << ";created" << std::endl;
}
Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(0);
	std::tm *currentTime = std::localtime(&now);
	std::cout << "[" << (currentTime->tm_year + 1900)
	<< std::setw(2) << std::setfill('0') << (currentTime->tm_mon + 1)
	<< std::setw(2) << std::setfill('0') << currentTime->tm_mday << "_"
	<< std::setw(2) << std::setfill('0') << currentTime->tm_hour
	<< std::setw(2) << std::setfill('0') << currentTime->tm_min
	<< std::setw(2) << std::setfill('0') << currentTime->tm_sec << "]";
}

void	Account::makeDeposit(int deposit)
{
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
	<< "p_amount:" << _amount << ";"
	<< "deposits:" << deposit << ";";
	_amount += deposit;
	_nbDeposits++;
	std::cout << "amount:" << _amount << ";"
	<< "_nbDeposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawal:refused" << std::endl;
		return (1);
	}
	else
	{
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";";
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";"
		<< "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (0);
	}
}

int		Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "deposits:" << _nbDeposits << ";"
	<< "withdrawals:" << _nbWithdrawals << std::endl;
}


int	Account::getNbAccounts()
{
	return (_nbAccounts);
}
int	Account::getTotalAmount()
{
	return (_totalAmount);
}
int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";"
	<< "total:" << _totalAmount << ";"
	<< "deposits:" << _totalNbDeposits << ";"
	<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}
