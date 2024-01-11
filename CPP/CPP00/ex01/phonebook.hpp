#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "contact.hpp"

class PhoneBook
{
	private:
	Contact contacts[8];
	int	num_contacts;

	public:
	void add(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
	void search();
	void information(int index);
	PhoneBook();
};

#endif