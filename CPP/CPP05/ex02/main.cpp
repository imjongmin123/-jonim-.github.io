#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	AForm* p = new PresidentialPardonForm("home");
	AForm* s = new ShrubberyCreationForm("home2");
	AForm* r = new RobotomyRequestForm("home3");

	Bureaucrat* b = new Bureaucrat("man", 1);
	try{
		b->signForm(*p);
		b->executeForm(*p);
		b->signForm(*s);
		b->executeForm(*s);
		b->signForm(*r);
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