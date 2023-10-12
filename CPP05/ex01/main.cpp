#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat man("developer", 10);
	Bureaucrat man2("developer2", 5);
	Form	   work("meeting", 5, 10);

	try
	{
		work.beSigned(man);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;;
	}
	man.signForm(work);

	// try
	// {
	// 	work.beSigned(man);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;;
	// }
}