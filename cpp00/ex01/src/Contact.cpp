#include "Contact.hpp"

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

void	Contact::set_first_name(std::string first_name) {
	this->_first_name = first_name;
}

std::string	Contact::get_first_name(void) const {
	return (this->_first_name);
}

void	Contact::set_last_name(std::string last_name) {
	this->_last_name = last_name;
}

std::string	Contact::get_last_name(void) const {
	return (this->_last_name);
}

void	Contact::set_nickname(std::string nickname) {
	this->_nickname = nickname;
}

std::string	Contact::get_nickname(void) const {
	return (this->_nickname);
}

void	Contact::set_phone(std::string phone) {
	this->_phone = phone;
}

std::string	Contact::get_phone(void) const {
	return (this->_phone);
}

void	Contact::set_darkest_secret(std::string darkest_secret) {
	this->_darkest_secret = darkest_secret;
}

std::string	Contact::get_darkest_secret(void) const {
	return (this->_darkest_secret);
}

