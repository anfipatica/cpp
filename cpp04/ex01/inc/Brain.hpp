#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
public:
	Brain(void);
	Brain(const Brain &brain);
	Brain &operator=(const Brain &brain);
	~Brain(void);

	std::string	get_idea(const unsigned int index) const;
	void	set_idea(const std::string idea, const unsigned int index);
	void	print_ideas(void) const;
private:
	static const int _number_of_ideas = 100;
	std::string	_ideas[_number_of_ideas];
};

#endif