#include "phonebook.hpp"
#include "contact.hpp"

int	main()
{
	PhoneBook phonebook;

	std::string input;
	while (1)
	{
		std::cout << "command input : ";
		getline(std::cin, input);
		if (std::cin.eof())
			{
				std::cout << "EOF" << std::endl;
				break;
			}
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			std::string first;
			std::string last;
			std::string nick;
			std::string phone;
			std::string secret;
			std::cout << "first name input : ";
			std::cin >> first;
			std::cout << "last name input : ";
			std::cin >> last;
			std::cout << "nick name input : ";
			std::cin >> nick;
			std::cout << "phone number input : ";
			std::cin >> phone;
			std::cout << "darkest secret input : ";
			std::cin >> secret;
			phonebook.add(first, last, nick, phone, secret);
		}
		else if (input == "SEARCH")
		{
			int index;
			phonebook.search();
			std::cout << "index input : ";
			std::cin >> index;
			if (std::cin.eof())
			{
				std::cout << "EOF" << std::endl;
				break;
			}
			else if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Please enter a number." << std::endl;
				continue;
			}
			if(index >= 1 && index <= 8)
				phonebook.information(index);
			else
				std::cout << "invalid index number" << std::endl;
		}
		else
			std::cout << "invalid command" << std::endl;
		continue;
	}
}