#include "BitcoinExchange.hpp"

bool		verifydate(std::string& line)
{
	int year = static_cast<int>(std::strtod(line.substr(0, 4).c_str(), NULL));
	int mon = static_cast<int>(std::strtod(line.substr(5, 2).c_str(), NULL));
	int day = static_cast<int>(std::strtod(line.substr(8, 2).c_str(), NULL));
	switch (mon)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day < 1 || day > 31)
			return (1);
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 1 || day > 30)
			return (1);
		break;
	case 2:
		if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0 && (day < 1 || day > 29))
			return (1);
		else if (year % 4 == 0 && year % 100 == 0 && year % 400 != 0  && (day < 1 || day > 28))
			return (1);
		else if (year % 4 == 0 && year % 100 != 0 && year % 400 != 0 && (day < 1 || day > 29))
			return (1);
		else if (year % 4 != 0 && year % 100 != 0 && year % 400 != 0 && (day < 1 || day > 28))
			return (1);
		break;
	default:
		return (1);
		break;
	}
	return (0);
}

bool		checkDate(std::string& line)
{
	size_t i = 0;
	while (i < line.size())
	{
		if (i == 4 || i == 7)
		{
			if (line[i] != '-')
				break;
		}
		else if (i < 10 && !std::isdigit(line[i]))
			break;
		i++;
		if (i == line.size())
			return (0);
	}
	std::cout << "data is error in data.csv" << std::endl;
	return (1);
}

long long	dateformat(std::string& line)
{
	std::string tmp;
	for (int i = 0; i < 10; i++)
	{
		if (std::isdigit(line[i]))
			tmp += line[i];
	}
	long long ret;
	std::stringstream stream(tmp);
	stream >> ret;
	return ret;
}

double rateformat(std::string& line)
{
	std::string format = line.substr(11);
	char *ptr;
	double ret = std::strtod(format.c_str(), &ptr);
	if (*ptr != '\0')
		return (-1);
	return ret;
}

double	valueformat(std::string& line)
{
	size_t pos = line.find('|');
	if (pos == std::string::npos || pos != 11)
		return (BAD_INPUT);
	std::string str = line.substr(line.find('|') + 1);
	char *endptr;
	double dvalue = std::strtod(str.c_str(), &endptr);
	if (*endptr != '\0')
		return (BAD_INPUT);
	if (errno == ERANGE || dvalue < std::numeric_limits<int>::min() \
		|| dvalue > std::numeric_limits<int>::max())
		return (TOO_LARGE_NUM);
	if (dvalue < 0)
		return (NOT_POSITIVE);
	return (dvalue);
}





BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& others)
{
	if (this == &others)
		return;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& others)
{
	if (this == &others)
		return *this;
	return *this;
}

void	BitcoinExchange::AddRate(long long date_, float rate)
{
	CoinRate[date_] = rate;
}

void	BitcoinExchange::print(long long date_, double value)
{
	if (CoinRate.find(date_) != CoinRate.end())
	{
		printDate(date_);
		std::cout << " >= " << value << " = " \
		<< value * CoinRate.find(date_)->second << std::endl;
	}
	else
	{
		long long temp = date_;
		while (1)
		{
			long long min = CoinRate.begin()->first;
			if (CoinRate.find(temp) != CoinRate.end())
			{
				printDate(date_);
				std::cout << " => " << value << " = " \
				<< value * CoinRate.find(temp)->second << std::endl;
				break ;
			}
			temp--;
			if (temp < min)
			{
				std::cout << "not found valid date in data.csv" << std::endl;
				return ;
			}
		}
	}
}

void	BitcoinExchange::printDate(long long date_)
{
	std::string printstr = std::to_string(date_);
	std::string year = printstr.substr(0, 4);
	std::string month = printstr.substr(4, 2);
	std::string day = printstr.substr(6, 2);
	std::cout << year << "-" << month << "-" << day;
}

bool	BitcoinExchange::dataMaping(std::ifstream& data)
{
	std::string line;
	std::getline(data, line);
	while (std::getline(data, line))
	{
		if (checkDate(line))
			return (1);
		long long date_ = dateformat(line);
		double rate_ = rateformat(line);
		if (rate_ < 0)
			return (1);
		AddRate(date_, rate_);
	}
	return (0);
	
}

bool	BitcoinExchange::Exchange(std::ifstream& input)
{
	std::string line;
	std::getline(input, line);
	if (line.compare("date | value"))
	{
		std::cout << "first line is error" << std::endl;
		return (1);
	}
	while (std::getline(input, line))
	{
		if (checkDate(line) || verifydate(line))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		long long date_ = dateformat(line);
		double value = valueformat(line);
		if (value == NOT_POSITIVE)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (value == BAD_INPUT)
		{
			std::cout << "Error: bad input => ";
			printDate(date_);
			std::cout << "\n";
			continue;
		}
		else if (value == TOO_LARGE_NUM)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		print(date_, value);
	}
	return (0);
}





CheckArg::CheckArg() {}
CheckArg::~CheckArg() {}
CheckArg::CheckArg(const CheckArg& others)
{
	if (this == &others)
		return ;
}
CheckArg& CheckArg::operator=(const CheckArg& others)
{
	if (this == &others)
		return *this;
	return *this;
}

bool	CheckArg::checkfile(std::ifstream& data, std::ifstream& input)
{
	if (!data.is_open())
	{
		std::cout << "data.csv is not exist" << std::endl;
		return (1);
	}
	if (!input.is_open())
	{
		std::cout << "input file is not exist" << std::endl;
		data.close();
		return (1);
	}
	return (0);
}