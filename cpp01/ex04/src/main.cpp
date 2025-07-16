#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define ERROR 1
#define OK 0

/**
 * @brief A version of std::string.replace().
 * 
 * @param str the string to make the replaces in.
 * @param s1 The string to be replaced.
 * @param s2 The string to replace with.
 */
void	my_string_replace(std::string &str, std::string s1, std::string s2)
{
	size_t	replace_index = std::string::npos;

	while (true)
	{
		
		replace_index = str.find(s1,
			(replace_index == std::string::npos ? 0: replace_index + s2.length()));
		if (replace_index == std::string::npos)
			break ;
		str.erase(replace_index, s1.length());
		str.insert(replace_index, s2);
	}
}

/**
 * @brief Copies the content of ifs into ofs, replacing every ocurrence of s1 with s2.
 * 
 * It will copy *ifs* buffer inside *aux_ostringstream* and use that ostringstream variable
 * to transform said buffer into a string to work with.
 * 
 * @param ifs Input File Stream.
 * @param ofs Output File Stream.
 * @param s1 The string to be replaced.
 * @param s2 The string to replace with.
 */
void	copy_to_file(std::ifstream &ifs, std::ofstream &ofs, std::string s1, std::string s2)
{
	std::ostringstream aux_ostringstream;
	std::string file_content;

	aux_ostringstream << ifs.rdbuf();
	file_content = aux_ostringstream.str();

	my_string_replace(file_content, s1, s2);
	ofs << file_content;
}

/**
 * @brief Opens the input file and creates the output file. Checks in case the input file was not found
 *and wheter there was some error while creating and opening the output file.
 * 
 * @param ifs Input File Stream. A reference to the ifstream where the input file will be held.
 * @param ofs Output File Stream. A reference to the ofstream where the output file will be held.
 * @param file_name the file name received as an argument.
 * @return Wheter the process was a success or not.
 */
int	open_files(std::ifstream &ifs, std::ofstream &ofs, std::string file_name)
{
	ifs.open(file_name.c_str());

	if (ifs.is_open() == false)
	{
		std::cerr << "File '" << file_name << "' not found" << std::endl;
		return (ERROR);
	}
	ofs.open(file_name.append(".replace").c_str());
	if (ofs.is_open() == false)
	{
		std::cerr << "File '" << file_name << ".replace' could not be created" << std::endl;
		return (ERROR);
	}
	return (OK);
}

int	main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;

	if (argc != 4)
	{
		std::cerr << "Invalid number of arguments :(\n\n"\
			"-> USAGE: ./new_sed <file_name> <s1> <s2>" << std::endl;
		return (1);
	}
	if (open_files(ifs, ofs, argv[1]) == ERROR)
		return (1);
	copy_to_file(ifs, ofs, argv[2], argv[3]);
	return (0);
}