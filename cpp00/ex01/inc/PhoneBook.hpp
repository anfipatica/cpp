#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		n;
		void	func(char *s);
		void	func(int s);
};

#endif