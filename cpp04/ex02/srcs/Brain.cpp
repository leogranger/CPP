#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy assignment operator called." << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called." << std::endl;
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index > 99 || index < 0)
		return ;
	ideas[index] = idea;
}

std::string	Brain::getIdea(int index)
{
	return (ideas[index]);
}