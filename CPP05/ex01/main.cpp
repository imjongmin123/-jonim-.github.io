#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat man("developer", 10);
	Bureaucrat man2("developer2", 5);
	Form	   work("meeting", 5, 10);

	man.signForm(work);
	man2.signForm(work);
}