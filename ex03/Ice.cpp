
#include "Ice.hpp"

/**
 * @brief This constructor initializes the base 
 * class AMateria with the type "ice" (AMateria takes at least
 * one string parameter).
 */
Ice::Ice(void) : AMateria("ice")
{
    std::cout << "Ice default constructor called." << std::endl;
}

/**
 * @brief The copy constructor in the AMateris class takes a string
 * type as a parameter, which is why we are feeding the 
 * type "ice" on this end.
 */     
Ice::Ice(const Ice &other) : AMateria("ice")
{
    std::cout << "Ice copy constructor called." << std::endl;
    *this = other;
}

/**
 * @brief Destroys the Ice object.
 *        Prints a message indicating that the destructor is called for Ice.
 */
Ice::~Ice(void)
{
    std::cout << "Ice destructor called." << std::endl;
}

/**
 * @brief Assigns another Ice object to this Ice.
 * 
 * @param other The Ice object to assign.
 * @return Ice& A reference to this Ice object after assignment.
 */      
Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Ice assignment operator called." << std::endl;
    _type = other._type; 
    return (*this);
}

/**
 * @brief Clones the Ice object.
 * 
 * @return AMateria* A pointer to the cloned Ice object.
 */
AMateria *Ice::clone(void) const
{
    return (new Ice());
}

/**
 * @brief Uses the Ice on a target character.
 *        Prints a message indicating that the Ice is used on the target.
 * 
 * @param target The target character to use the Ice on.
 */
void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
