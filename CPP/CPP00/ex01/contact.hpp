#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	public:
	void Set_contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
	void Display();
	void detail();
	Contact ();
};
#endif