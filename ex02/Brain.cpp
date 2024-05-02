#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called." << std::endl;
    *this = other;
}

Brain::~Brain()
{
    std::cout << "Destructed brain." << std::endl;
}

Brain   &Brain::operator=(const Brain &other)
{
    int i;

    std::cout << "Brain assignment overload operator called." << std::endl;
    if (this != &other)
    {
        i = 0;
        while (i < CAPACITY)
        {
            _ideas[i] = other._ideas[i];
            ++ i;
        } 
    }
    return (*this);
}

std::string const & Brain::getIdea(int index) const
{
	if (index < 0)
		index = 0;
	return (this->_ideas[index % (CAPACITY - 1)]);
}

void	Brain::setIdea(int index, std::string const & idea)
{
	if (index < 0)
		return ;
	this->_ideas[index % (CAPACITY - 1)] = idea;
	return ;
}
