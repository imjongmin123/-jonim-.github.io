#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	std::string target;

	public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();

	ShrubberyCreationForm(std::string target_);
	ShrubberyCreationForm(const ShrubberyCreationForm& S_C_Form);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& S_C_Form);
	void	execute(Bureaucrat const & executor) const;
};

#endif
