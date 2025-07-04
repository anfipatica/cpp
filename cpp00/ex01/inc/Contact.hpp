#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "Contact.hpp"
# include <string>

class Contact {
	public:
		Contact(void);
		~Contact(void);
		void	set_first_name(std::string first_name);
		void	set_last_name(std::string last_name);
		void	set_nickname(std::string nickname);
		void	set_phone(std::string phone);
		void	set_darkest_secret(std::string darkest_secret);
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone(void) const;
		std::string	get_darkest_secret(void) const;

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone;
		std::string	_darkest_secret;
};

#endif