#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();

	ShrubberyCreationForm(const ShrubberyCreationForm& S_C_Form);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& S_C_Form);
	void	execute(Bureaucrat const & executor) const;
};

#endif
