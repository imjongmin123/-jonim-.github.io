#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>

#define FAIL 0
#define SUCCESS 1
#define PLUS 1
#define MINUS 2
#define MULTI 3
#define DIVIDE 4

class RPN
{
	private:	
	RPN(const RPN& others);
	RPN& operator=(const RPN& others);

	public:
	RPN();
	~RPN();

	void	cal(std::string str);
	bool	check(int ac, char** av);
	int		isoper(char c);
	double	plus(double first, double second);
	double	minus(double first, double second);
	double	multi(double first, double second);
	double	divide(double first, double second);
};

#endif