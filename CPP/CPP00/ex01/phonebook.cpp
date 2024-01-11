#include "phonebook.hpp"

void PhoneBook::add(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
	contacts[num_contacts].Set_contact(first, last, nick, phone, secret);
	if (num_contacts == 7)
		num_contacts = 0;
	else
		num_contacts++;
}

void PhoneBook::search()
{
	for(int i = 0; i <= 7; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i + 1; 
		std::cout << "|";
		contacts[i].Display();
	}
}

void PhoneBook::information(int index)
{
	index--;
	contacts[index].detail();
}

PhoneBook::PhoneBook()
	{
		num_contacts = 0;
	}