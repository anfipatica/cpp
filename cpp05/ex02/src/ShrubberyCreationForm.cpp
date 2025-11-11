#include "../inc/ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	cout << "constructor called for ShrubberyCreationForm\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &form):
	AForm(form)
{
	*this = form;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm &form)
{
	if (this != &form)
	{
		AForm::operator=(form);
		_target = form._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	cout << "Destructor called for ShrubberyCreationForm\n";
}

void	ShrubberyCreationForm::execute(void) const
{
	std::ofstream	file;
	std::string		file_name = _target + "_schrubbery";

	file.open(file_name.c_str(), std::ios::trunc);
	file << "            .        +          .      .          .\n" <<
	"     .            _        .                    .\n" <<
	"  ,              /;-._,-.____        ,-----._\n" <<
	" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n" <<
	"  `                 \\   _|`=:_::.`.);  \\ __/ /\n" <<
	"                      ,    `./  \\:. `.   )==-'  .\n" <<
	"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n" <<
	".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n" <<
	"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n" <<
	"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n" <<
	"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n" <<
	"              \\:  `  X` _| _,\\/'   .-'\n" <<
	".               \":._:`\\____  /:'  /      .           .\n" <<
	"                    \\::.  :\\/:'  /              +\n" <<
	"   .                 `.:.  /:'  }      .\n" <<
	"           .           ):_(:;   \\           .\n" <<
	"                      /:. _/ ,  |\n" <<
	"                   . (|::.     ,`                  .\n" <<
	"     .                |::.    {\\\n" <<
	"                      |::.\\  \\ `.\n" <<
	"                      |:::(\\    |\n" <<
	"              O       |:::/{ }  |                  (o\n" <<
	"               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n" <<
	"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n" <<
	"dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~\"";

	file.close();
}

