#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern
{
	public:
	Intern();
	~Intern();

	Intern(const Intern& Intern);
	Intern& operator=(const Intern& Intern);
	AForm* makeForm(std::string name_form, std::string target_form);
};

#endif
