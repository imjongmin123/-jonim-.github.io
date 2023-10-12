#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void	v()
{
	system("leaks a.out");
}

int main()
{
	atexit(v);
	Intern *man = new Intern();
	AForm *f = man->makeForm("presidential pardon", "ben");
	std::cout << f->getName() << std::endl;
	delete man;
	delete f;
}