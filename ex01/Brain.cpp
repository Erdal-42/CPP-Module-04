#include "Brain.hpp"

/**
 * @brief Constructs a new Brain object.
 *        Prints a message indicating that the default constructor is called.
 */
Brain::Brain(void)
{
    std::cout << "Brain default constructor called." << std::endl;
}

/**
 * @brief Copy constructs a new Brain object from another Brain.
 * 
 * @param other The Brain object to copy.
 */
Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called." << std::endl;
    *this = other;
}

/**
 * @brief Destroys the Brain object.
 *        Prints a message indicating that the Brain is destroyed.
 */
Brain::~Brain()
{
    std::cout << "Destructed brain." << std::endl;
}

/**
 * @brief Assigns another Brain object to this Brain.
 * 
 * @param other The Brain object to assign.
 * @return Brain& A reference to this Brain object after assignment.
 */
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

/**
 * @brief Gets the idea at the specified index.
 *        If the index is negative, it wraps around to the end of the array.
 * 
 * @param index The index of the idea to get.
 * @return std::string const& The idea at the specified index.
 */
std::string const & Brain::getIdea(int index) const
{
	if (index < 0)
		index = 0;
	return (this->_ideas[index % (CAPACITY - 1)]);
}

/**
 * @brief Sets the idea at the specified index.
 *        If the index is negative, the idea is not set.
 * 
 * @param index The index of the idea to set.
 * @param idea The idea to set.
 */
void	Brain::setIdea(int index, std::string const & idea)
{
	if (index < 0)
		return ;
	this->_ideas[index % (CAPACITY - 1)] = idea;
	return ;
}
