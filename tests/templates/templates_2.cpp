
#include <iostream>
#include <string>

template<typename T>
class	List {
public:

	List<T>(const T &content): _content(&content) { std::cout << "constructor: " << *_content << "\n";};
	List<T>(const List<T> &list) { };
	List<T>	&operator=(const List<T> &list) { this->_content = list._content; return this;};
	~List(void) {};
	const T	*get_content(void) {return (_content);};

private:
	const T	*_content;
	List<T>	*_next;
};


int	main(void)
{
	int	n = 42;
	List<int> lista_ints(n);
	List<std::string> lista_str("Hola caracola");

	std::cout << *lista_ints.get_content() << "\n";
	std::cout << *lista_str.get_content() << "\n";
}