#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:AForm()
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:AForm("ShrubberyCreationForm", 145, 137)
	,_target(target)
{
	std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:AForm(other)
{
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	std::cout << "ShrubberyCreationForm copy assignment operator called." << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::createTree(void)
{
	std::ofstream newFile(_target + std::string("_shrubbery").c_str());
	if (newFile)
	{
		newFile << "            .        +          .      .          ." << std::endl
				<< "     .            _        .                    ." << std::endl
				<< "  ,              /;-._,-.____        ,-----.__" << std::endl
				<< " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl
				<< "  `                 \   _|`'=:_::.`.);  \ __/ /" << std::endl
				<< "                      ,    `./  \:. `.   )==-'  ." << std::endl
				<< "    .      ., ,-=-.  ,\, +#./`   \:.  / /           ." << std::endl
				<< ".           \/:/`-' , ,\ '` ` `   ): , /_  -o" << std::endl
				<< "       .    /:+- - + +- : :- + + -:'  /(o-) \)     ." << std::endl
				<< "  .      ,=':  \    ` `/` ' , , ,:' `'--'.--'---._/`7" << std::endl
				<< "   `.   (    \: \,-._` ` + '\, ,'   _,--._,---'o.__/" <<std::endl
				<< "              \:  `  X` _| _,\/'   .-'" << std::endl
				<< ".               ':._:'\____  /:\  /      .           ." << std::endl
				<< "                    \::.  :\/:'  /              +" << std::endl
				<< "   .                 `.:.  /:'  }      ." << std::endl
				<< "           .           ):_(:;   \           ." << std::endl
				<< "                      /:. _/ ,  |" << std::endl
				<< "                   . (|::.     ,`                  ." << std::endl
				<< "     .                |::.    { |" << std::endl
				<< "                      |::.\  \ `." << std::endl
				<< "                      |::::\    |" << std::endl
				<< "              O       |:::/{ }  |                  (o" << std::endl
				<< "               )  ___/#\::`/ (O ''==._____   O, (O  /`" << std::endl
				<< "          ~~~w/w~o~~,\o `:/,-(~`'~~~~~~~~.o~\~/~w|/~" << std::endl;
	}
	else
		std::cout << "Couldn't open file from form: " << this->getName() << std::endl;
}
