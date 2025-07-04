#include "PhoneBook.hpp"

#include <iomanip> //setfill, setw
#include <cstdlib> //atoi
#include <sstream> //stringstream

#define COLUMN_WIDTH 10
#define INVALID_INDEX -1

void	format_field(std::string field)
{
	std::cout << GREEN << "|" << STD;
	if (field.length() > COLUMN_WIDTH)
		std::cout << field.substr(0, COLUMN_WIDTH - 1) << ".";
	else
	{
		std::cout << std::setfill(' ') << std::setw(COLUMN_WIDTH);
		std::cout << field;
	}
}

int	PhoneBook::_validate_index_input(std::string index_input) const
{
	int	index_len = 0;

	for (int i = 0; index_input[i]; i++)
	{
		if (std::isspace(index_input[i]))
			continue;
		if (std::isdigit(index_input[i]))
			index_len++;
		else
		{
			return (INVALID_INDEX);
		}
	}
	if (index_len == 1)
		return (std::atoi(index_input.c_str()));
	else
		return (INVALID_INDEX);
}

void	PhoneBook::_format_contact_display(std::string field_name, std::string field_info) const
{
	std::cout << PURPLE << "| " << field_name<< std::endl;
	std::cout << "|" << STD << "  · " << field_info << std::endl;
}

void	PhoneBook::_select_contact_menu(void) const
{
	std::string	index_input;
	int	index;

	std::cout << BLUE << "\n\nSelect an index to see the contact information: " << STD;
	std::getline(std::cin, index_input);
	index = _validate_index_input(index_input);
	if (index == INVALID_INDEX)
	{
		std::cout << RED << "\nThe index must be a a number between 1 - 8"  << STD << std::endl;
		return ;
	}
	if (this->_contacts[index - 1].get_last_name().empty() == true)
	{
		std::cout << RED << "\nSorry, there is no contact for the specified index" << STD << std::endl;
		return ;
	}
	_format_contact_display("FIRST NAME", this->_contacts[index - 1].get_first_name());
	_format_contact_display("LAST NAME", this->_contacts[index - 1].get_last_name());
	_format_contact_display("NICKNAME", this->_contacts[index - 1].get_nickname());
	_format_contact_display("PHONE NUMBER", this->_contacts[index - 1].get_phone());
	_format_contact_display("DARKEST SECRET", this->_contacts[index - 1].get_darkest_secret());
}

void	PhoneBook::display_contacts(int contact_index) const
{

	if (contact_index == 0)
	{
		std::cout << RED << "\nNo contacts have been added yet :(\n" << STD << std::endl;
		return ;
	}
	std::cout << GREEN << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|   INDEX  |   NAME   |LAST  NAME| NICKNAME |" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (this->_contacts[i].get_last_name() == "")
			break;
		std::cout << GREEN << "+----------+----------+----------+----------+"<< STD << std::endl;
		std::stringstream ss;
		ss << i + 1;
		format_field(ss.str());
		format_field(this->_contacts[i].get_first_name());
		format_field(this->_contacts[i].get_last_name());
		format_field(this->_contacts[i].get_nickname());
		std::cout << GREEN << "|" << STD << std::endl;
	}
	std::cout << GREEN << "+----------+----------+----------+----------+" << STD << std::endl;
	_select_contact_menu();
}
