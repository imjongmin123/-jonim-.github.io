#include "RPN.hpp"
#include <stack>
#include <exception>
#include <limits>


RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& others)
{
	if (this == &others)
		return ;
}
RPN& RPN::operator=(const RPN& others)
{
	if (this == &others)
		return *this;
	return *this;
}

int	RPN::isoper(char c)
{
	if (c == '+')
		return (PLUS);	
	if (c == '-')
		return (MINUS);
	if (c == '*')
		return (MULTI);
	if (c == '/')
		return (DIVIDE);
	return (FAIL);
}

double	RPN::plus(double first, double second)
{
	if (std::abs(first + second) > std::numeric_limits<double>::max())
		throw::std::out_of_range("ouf of range !!!!");
	return (first + second);
}

double	RPN::minus(double first, double second)
{
	if (std::abs(first - second) > std::numeric_limits<double>::max())
		throw::std::out_of_range("ouf of range !!!!");
	return (first - second);
}
double	RPN::multi(double first, double second)
{
	double epsilion = std::numeric_limits<double>::epsilon();
	if (std::abs(first) < epsilion || std::abs(second) < epsilion)
		throw::std::invalid_argument("0 is impossible in multi operation");
	if (std::abs(first * second) > std::numeric_limits<double>::max())
		throw::std::out_of_range("ouf of range !!!!");
	return (first * second);
}
double	RPN::divide(double first, double second)
{
	double epsilion = std::numeric_limits<double>::epsilon();
	if (std::abs(first) < epsilion || std::abs(second) < epsilion)
		throw::std::invalid_argument("0 is impossible in divide operation");
	if (std::abs(first / second) > std::numeric_limits<double>::max())
		throw::std::out_of_range("ouf of range !!!!");
	return (first / second);
}



void	RPN::cal(std::string str)
{
	std::stack<double>	mystack;
	size_t i = 0;
	while(i < str.size())
	{
		if (isoper(str[i]))
		{
			int operation = isoper(str[i]);
			double second = mystack.top();
			mystack.pop();
			double first = mystack.top();
			mystack.pop();
			try{
				double temp;
				switch (operation)
				{
				case PLUS:
					temp = plus(first, second);
					break;
				case MINUS:
					temp = minus(first, second);
					break;
				case MULTI:
					temp = multi(first, second);
					break;
				case DIVIDE:
					temp = divide(first, second);
					break;
				default:
					break;
				}
				mystack.push(temp);
			}
			catch(std::exception& e)
			{
				std::cout << e.what() << std::endl;
				return ;
			}
		}
		else
		{
			const char* temp = &(str[i]);
			mystack.push(std::strtod(temp, NULL));
		}
		i += 2;
	}
	std::cout << mystack.top() << std::endl;
}

bool	RPN::check(int ac, char** av)
{
	if (ac != 2)
		return (FAIL);
	std::string arg = av[1];
	unsigned int num = 0;
	unsigned int oper = 0;

	for (unsigned int i = 0; i < arg.size(); i++)
	{
		if (i % 2 == 1 && arg[i] == ' ')
			continue;
		else if (std::isdigit(arg[i]))
			num++;
		else if (isoper(arg[i]))
			oper++;
		else
			return (FAIL);
		if (oper + 1 > num)
			return (FAIL);
	}
	if (num != oper + 1)
		return (FAIL);
	return (SUCCESS);
}