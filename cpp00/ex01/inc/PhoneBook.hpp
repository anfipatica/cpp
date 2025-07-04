#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "common_defines.hpp"

#include <iostream>

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);

		int		add_contact(int contact_index);
		void	display_contacts(int contact_index) const;
		
	private:
		Contact _contacts[8];
		
		int		_validate_index_input(std::string index_input) const;
		void	_select_contact_menu(void) const;
		int		_get_valid_input(std::string prompt, std::string	*input);
		int		_create_contact(Contact &contact);
		void	_format_contact_display(std::string field_name, std::string field_info) const;
		int		_validate_phone(std::string phone) const;
	};

#endif
