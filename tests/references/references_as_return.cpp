#include <iostream>
#include <string>

class Student {

	public:
		Student(const std::string &login): _login(login)
		{}
		~Student(void) {}
		std::string	&get_login_ref() // por qué no puedo poner const??
		{
			return (_login);
		}
		const std::string &get_login_ref_const() const
		{
			return (_login);
		}
		std::string *get_login_ptr()
		{
			return (&_login);
		}
		const std::string *get_login_ptr_const() const
		{
			return (&_login);
		}
	private:
		std::string _login;
};

int	main(void)
{
	Student	bob = Student("bob");
	Student const jim = Student("jim");

	std::cout << bob.get_login_ref_const() << " " << jim.get_login_ref_const() << std::endl;
	std::cout << *(bob.get_login_ptr_const()) << " " << *(jim.get_login_ptr_const()) << std::endl;

	bob.get_login_ref() = "nuevo_bob";
	std::cout << bob.get_login_ref_const() << std::endl;

	*(bob.get_login_ptr()) = "nuevo_nuevérrimo_bob";
	std::cout << bob.get_login_ref_const() << std::endl;
}