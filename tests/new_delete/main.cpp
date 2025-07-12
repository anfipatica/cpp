#include <iostream>
#include <string>

class Student
{
	public:
		Student(void): _login("default_login")
		{
			std::cout << "Student " << _login << " is born" << std::endl;
		}
		Student(std::string login): _login(login)
		{
			std::cout << "Student " << _login << " is born" << std::endl;
		}
		~Student()
		{
			std::cout << "Student " << _login <<  " died" << std::endl;
		}
	private:
		std::string _login;
};

int main(void)
{
	Student	bob = Student("bob"); //stack
	Student	*jim = new Student("Jim"); //heap
	Student	*students_array = new Student[10];

	delete jim;
	delete [] students_array;
	return 0;
}
