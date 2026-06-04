#include "Sed.hpp"

Sed::Sed(const std::string &filename, const std::string &s1, const std::string &s2) 
	: _filename(filename)
	, _s1(s1)
	, _s2(s2)
{
	// std::cout << "Sed constructor called." << std::endl;
}

Sed::~Sed(void)
{
	// std::cout << "Sed destructor called." << std::endl;
}

std::string returnText(std::string filename)
{
	std::string	txt;
	std::string	wholeText;
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Could not open file." << std::endl;
		return "";
	}
	while (std::getline(file, txt))
	{
		wholeText += txt + '\n';
	}
	if (wholeText.empty())
	{
		std::cout << "File is empty." << std::endl;
		return "";
	}
	file.close();
	return wholeText;
}

void	Sed::findAndReplace()
{
	std::string text = returnText(_filename);
	if (text.empty())
		return ;
	std::string newFilename = _filename + ".replace";
	std::ofstream newFile(newFilename.c_str());
	if(_s1.empty())
	{
		newFile << text;
		return ;
	}
	size_t	startPos = 0;
	int	s1Len = _s1.length();
	while ((startPos = text.find(_s1)) != std::string::npos)
	{
		text.erase(startPos, s1Len);
		text.insert(startPos, _s2);
		startPos += _s2.length();;
	}
	newFile << text;
	newFile.close();
}
