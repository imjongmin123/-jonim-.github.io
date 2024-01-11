#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <limits>
#include <cerrno>
#include <cctype>
#include <cstdlib>
#include <string>

#define NOT_POSITIVE -1
#define BAD_INPUT -2
#define TOO_LARGE_NUM -3

class BitcoinExchange
{
	private:
	std::map<long long, float> CoinRate;

	public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& others);
	BitcoinExchange& operator=(const BitcoinExchange& others);

	void	AddRate(long long date_, float rate);
	void	print(long long date_, double value);
	void	printDate(long long date_);
	bool	dataMaping(std::ifstream& data);
	bool	Exchange(std::ifstream& input);

	std::string	convert(long long num);
};

class CheckArg
{
	private:

	public:
	CheckArg();
	~CheckArg();
	CheckArg(const CheckArg& others);
	CheckArg& operator=(const CheckArg& others);

	bool	checkfile(std::ifstream& data, std::ifstream& input);
};

bool			checkDate(std::string& line);
long long		dateformat(std::string& line);
double			rateformat(std::string& line);
double			valueformat(std::string& line);

#endif
