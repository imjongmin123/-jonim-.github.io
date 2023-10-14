#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	std::string target;

	public:
	PresidentialPardonForm();
	~PresidentialPardonForm();

	PresidentialPardonForm(std::string target_);
	PresidentialPardonForm(const PresidentialPardonForm& P_P_Form);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& P_P_Form);
	void	execute(Bureaucrat const & executor) const;
};

#endif
