#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <sstream>

class ScalarConverter
{
	private:
	ScalarConverter();
	virtual ~ScalarConverter();

	ScalarConverter(const ScalarConverter& S_C);
	ScalarConverter& operator=(const ScalarConverter& S_C);

	public:
	static void		convert(const std::string input);
	static int		CheckType(const std::string input);
	static void		detectChar(const std::string input);
	static void		detectInt(const std::string input);
	static void		detectFloat(const std::string input);
	static void		detectDouble(const std::string input);
	static void		except(const std::string input);
	static void		errcase();
};

#endif
