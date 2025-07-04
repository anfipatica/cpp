#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

int	PhoneBook::_validate_phone(std::string phone) const
{
	int	start = 0;

	if (phone[start] == '+' && std::isdigit(phone[start + 1]))
		start++;

	for (int j = start; phone[j]; j++)
	{
		if (std::isdigit(phone[j]) == false)
		{
			std::cout << RED << "\nINVALID PHONE NUMBER, It can only contain"\
				" numbers and an optional '+' at the beginning" << STD << std::endl;
			return (KO);
		}
	}
	return (OK);
}

int	PhoneBook::_get_valid_input(std::string prompt, std::string	*input)
{
	std::cout << GREEN << prompt << STD;
	std::getline(std::cin, *input);

	if ((*input).empty())
	{
		std::cout << RED << "\nINVALID INPUT: A contact cannot have an empty field" << STD << std::endl;
		return (KO);
	}
	if (prompt.compare("PHONE NUMBER: ") == OK)
		return (_validate_phone(*input));

	return (OK);
}

int	PhoneBook::_create_contact(Contact &contact)
{
	std::string	input;
	
	if (_get_valid_input("FIRST_NAME: ", &input) == KO)
		return (KO);
	contact.set_first_name(input);

	if (_get_valid_input("LAST_NAME: ", &input) == KO)
		return (KO);
	contact.set_last_name(input);

	if (_get_valid_input("NICKNAME: ", &input) == KO)
		return (KO);
	contact.set_nickname(input);

	if (_get_valid_input("PHONE NUMBER: ", &input) == KO)
		return (KO);
	contact.set_phone(input);

	if (_get_valid_input("DARKEST_SECRET: ", &input) == KO)
		return (KO);
	contact.set_darkest_secret(input);
	return (OK);
}

int	PhoneBook::add_contact(int contact_index)
{
	Contact contact;

	if (_create_contact(contact) == KO)
		return (KO);
	this->_contacts[contact_index % MAX_CONTACTS] = contact;
	return (OK);
}

