#include "contact.hpp"

void Contact::Set_contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
	first_name = first;
	last_name = last;
	nick_name = nick;
	phone_number = phone;
	darkest_secret = secret;
}

void Contact::Display()
{
	if (first_name.length() > 10)
	{
		for(size_t i = 0; i < 9; i++)
			std::cout << first_name[i];
		std::cout << ".";
	}
	else
		std::cout << std::setw(10) << first_name;
	std::cout << "|";
	if (last_name.length() > 10)
	{
		for(size_t i = 0; i < 9; i++)
			std::cout << last_name[i];
		std::cout << ".";
	}
	else
		std::cout << std::setw(10) << last_name;
	std::cout << "|";
	if (nick_name.length() > 10)
	{
		for(size_t i = 0; i < 9; i++)
			std::cout << nick_name[i];
		std::cout << ".";
	}
	else
		std::cout << std::setw(10) << nick_name;
	std::cout << "|" << std::endl;
}

void Contact::detail()
{
	std::cout << "first name is : " << first_name << std::endl;
	std::cout << "last name is : " << last_name << std::endl;
	std::cout << "nick name is : " << nick_name << std::endl;
	std::cout << "phone number is : " << phone_number << std::endl;
	std::cout << "darkest secret is : " << darkest_secret << std::endl;
}

Contact::Contact()
	{
		first_name = "";
		last_name = "";
		nick_name = "";
		phone_number = "";
		darkest_secret = "";
	}