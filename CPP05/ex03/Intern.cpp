#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
	std::cout << "[Intern] default constructor is called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "[Intern] destructor is called" << std::endl;
}

Intern::Intern(const Intern& Intern)
{
	std::cout << "[Intern] copy constructor is called" << std::endl;
	if (this == &Intern)
		return ;
}

Intern& Intern::operator=(const Intern& Intern)
{
	std::cout << "[Intern] operator is called" << std::endl;
	if (this == &Intern)
		return *this;
	return (*this);
}

AForm* Intern::makeForm(std::string name_form, std::string target_form)
{
	const  char *form[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int index = 0;
	for (int i = 0; i < 3; i++)
	{
		int result = name_form.compare(form[i]);
		if (result == 0)
			break ;
		index++;
	}
	AForm *f;
	switch (index)
	{
	case 0:
		f = new PresidentialPardonForm(target_form);
		break;
	
	case 1:
		f = new RobotomyRequestForm(target_form);
		break;
	
	case 2:
		f = new ShrubberyCreationForm(target_form);
		break;

	default:
		std::cout << "invalid name_form!" << std::endl;
		f = NULL;
		break;
	}
	return (f);
}