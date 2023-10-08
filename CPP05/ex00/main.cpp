#include "Bureaucrat.hpp"

int main()
{
	// test0 normal case
	std::cout << "<test0 normal case>" << std::endl;
	try
	{
		Bureaucrat first_man("developer", 150);
		std::cout << first_man << std::endl;

		first_man.increment();
		std::cout << first_man << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "catch exception : " << e.what() << std::endl;
	}

	// test1 normal case
	std::cout << "<test1 normal case>" << std::endl;
	try
	{
		Bureaucrat first_man("developer", 1);
		std::cout << first_man << std::endl;

		first_man.decrement();
		std::cout << first_man << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "catch exception : " << e.what() << std::endl;
	}

	// test2 catch case1
	// std::cout << "<test2 catch case1>" << std::endl;
	// try
	// {
	// 	Bureaucrat first_man("developer", 1);
	// 	std::cout << first_man << std::endl;

	// 	first_man.increment();
	// 	std::cout << first_man << std::endl;
	// }
	// catch(std::exception& e)
	// {
	// 	std::cout << "catch exception : " << e.what() << std::endl;
	// }

	// test3 catch case2
	// std::cout << "<test3 catch case1>" << std::endl;
	// try
	// {
	// 	Bureaucrat first_man("developer", 200);
	// 	std::cout << first_man << std::endl;
	// }
	// catch(std::exception& e)
	// {
	// 	std::cout << "catch exception : " << e.what() << std::endl;
	// }
	return (0);
}