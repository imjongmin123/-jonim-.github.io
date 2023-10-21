#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& S_C)
{
	if (this == &S_C)
		return ;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& S_C)
{
	if (this == &S_C)
		return *this;
	return *this;
}

void	ScalarConverter::errcase()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

int	ScalarConverter::CheckType(std::string input)
{
	size_t len = input.size();
	if (len == 1 && (input[0] < '0' || input[0] > '9') && isprint(input[0]))
		return (1);
	if (!input.compare("inf") || !input.compare("+inf") || !input.compare("-inf") \
		|| !input.compare("inff") || !input.compare("+inff") || !input.compare("-inff") || !input.compare("nan"))
			return (5);
	int dot = 0;
	int f = 0;
	int e = 0;
	int sign = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (!isdigit(input[i]))
		{
			if (input[i] == '.')
				dot++;
			else if (input[i] == 'f' || input[i] == 'F')
				f++;
			else if (input[i] == 'e' || input[i] == 'E')
				e++;
			else if (input[i] == '-' || input[i] == '+')
				sign++;
			else
				return (0);
		}
		if (dot > 1 || f > 1 || e > 1 || sign > 1)
			return (0);
	}
	if (f == 1)
	{
		if (input.find("f") != std::string::npos && input.find("f") != len - 1)
			return (0);
		if (input.find("F") != std::string::npos && input.find("F") != len - 1)
			return (0);
	}
	if (e == 1)
	{
		for (size_t i = 0; i < len; i++)
		{
			if (input[i] == 'e' || input[i] == 'E')
			{
				if (i == 0 || !isdigit(input[i + 1]))
					return (0);
			}
		}
	}
	if (sign == 1 && input[0] != '-' && input[0] != '+')
		return (0);
	errno = 0;
	double d = std::strtod(input.c_str(), NULL);
	if (std::isnan(d) || (std::isinf(d)))
		return (5);
	if (errno != 0)
		return (0);
	if (f == 0 && dot == 0 && d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min())
		return (2);
	float fvalue = static_cast<float>(d);
	if (f == 1 && (d - static_cast<double>(fvalue)) < 0.01 && (d - static_cast<double>(fvalue)) > -0.01)
		return (3);
	return (4);
}

void	ScalarConverter::detectChar(const std::string input)
{
	char c = input[0];
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::detectInt(const std::string input)
{
	std::istringstream iss(input);
	int Ivalue;
	iss >> Ivalue;
	if (Ivalue > 0 && Ivalue < 200 && isprint(Ivalue))
		std::cout << "char: " << static_cast<char>(Ivalue) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "Int: " << Ivalue << std::endl;
	float f = static_cast<float>(Ivalue);
	if (Ivalue - static_cast<int>(f) < 0.01 && Ivalue - static_cast<int>(f) > -0.01)
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" <<std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(Ivalue) << std::endl;
}

void	ScalarConverter::detectFloat(const std::string input)
{
	double d = std::strtod(input.c_str(), NULL);
	float f = static_cast<float>(d);
	if (isinf(f) || isnan(f))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
		return ;
	}
	if (d - static_cast<double>(f) > 0.01 || d - static_cast<double>(f) < -0.01)
	{
		errcase();
		return ;
	}
	if (f > 0 && f < 200 && isprint(f))
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(f) << std::endl;
}		

void	ScalarConverter::detectDouble(const std::string input)
{
	double d = std::strtod(input.c_str(), NULL);
	if (d > 0 && d < 200 && isprint(d))
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (d > std::numeric_limits<int>::min() && d < std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	float f = static_cast<float>(d);
	if (isinf(f) || isnan(f) || ((d - static_cast<double>(f) < 0.01) && (d - static_cast<double>(f) > -0.01)))
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}	

void	ScalarConverter::except(const std::string input)
{
	double d = std::strtod(input.c_str(), NULL);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (!input.compare("inf") || !input.compare("+inf") || !input.compare("inff") || !input.compare("+inff") \
	|| (isinf(d) && input[0] == '+'))
	{
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (!input.compare("nan") || !input.compare("nanf"))
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string input)
{
	int detect = CheckType(input);
	switch (detect)
	{
	case 1:
		detectChar(input);
		break;
	case 2:
		detectInt(input);
		break;
	case 3:
		detectFloat(input);
		break;
	case 4:
		detectDouble(input);
		break;
	case 5:
		except(input);
		break;
	default:
		errcase();
		break;
	}
}