#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	int	contact_index = 0;


	while (true)
	{
		std::cout << BLUE << "PHONEBOOK > " << STD;
		std::getline(std::cin, input);
		if (input == "")
		{
			continue;
		}
		else if (input == "ADD")
		{
			if (phonebook.add_contact(contact_index) == KO)
				continue;
			contact_index++;
		}
		else if (input == "SEARCH")
			phonebook.display_contacts(contact_index);
		else if (input == "EXIT")
			break;
	}
	std::cout << PURPLE << "Thanks for using phonebookeitor 2.0   :)" << STD << std::endl;
	return (0);
}
