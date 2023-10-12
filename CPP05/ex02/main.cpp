#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	AForm* p = new PresidentialPardonForm();
	AForm* s = new ShrubberyCreationForm();
	AForm* r = new RobotomyRequestForm();

	Bureaucrat* b = new Bureaucrat("man", 1);
	try{
		b->executeForm(*p);
		b->executeForm(*s);
		b->executeForm(*r);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete b;
	delete p;
	delete s;
	delete r;
}