#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	try{

	Intern man;
	AForm* work;
	Bureaucrat *yesman = new Bureaucrat("yesman", 5);


	work = man.makeForm("robotomy request", "Bender");
	yesman->signForm(*work);
	yesman->executeForm(*work);
	delete work;
	work = man.makeForm("presidential pardon", "john");
	yesman->signForm(*work);
	yesman->executeForm(*work);
	delete work;
	work = man.makeForm("shrubbery creation", "john");
	yesman->signForm(*work);
	yesman->executeForm(*work);
	delete work;
	delete yesman;
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}