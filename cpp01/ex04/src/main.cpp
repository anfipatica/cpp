#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void	my_string_replace(std::string &str, std::string s1, std::string s2)
{
	size_t	replace_index;

	while (true)
	{
		replace_index = str.find(s1);
		std::cout << replace_index << std::endl;
		if (replace_index == std::string::npos)
			break ;
		str.erase(replace_index, s1.length());
		str.insert(replace_index, s2);

	}
}

int	copy_to_file(std::ifstream &ifs, std::string s1, std::string s2, std::string file_name)
{
	std::string aux_string;

	std::ofstream ofs(file_name.append(".replace").c_str());
	std::cout << s1 << " " << s2 << " " << file_name << std::endl;
	while (true)
	{
		ifs >> aux_string;
		if (ifs.rdstate() != 0)
			return (0);
		my_string_replace(aux_string, s1, s2);
		ofs << aux_string;
		while (std::isspace(ifs.peek()))
		{
			std::cout << (char)ifs.peek();
			ofs << (char)ifs.peek();
			ifs.ignore(1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Invalid number of arguments :(" << std::endl;
		return (1);
	}

	std::ifstream ifs(argv[1]);
	if (ifs.is_open() == false)
	{
		std::cerr << "File '" << argv[1] << "' not found" << std::endl;
		return (1);
	}

	copy_to_file(ifs, argv[2], argv[3], argv[1]);

	return (0);
}