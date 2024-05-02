#include "Cat.hpp"

/**
 * @brief Default constructor for the Cat class.
 *        Initializes the type of the cat to "Cat".
 */
Cat::Cat(void) : Animal()
{
    _type = "Cat";
#ifdef TRACE
    std::cout << _type << " constructed." << std::endl;  
#endif
}

/**
 * @brief Copy constructor for the Cat class.
 *        Copies the type from another Cat object.
 * 
 * @param other The Cat object to copy from.
 */
Cat::Cat(const Cat &other) : Animal()
{
#ifdef TRACE
    std::cout << "Cat copy constructor called." << std::endl; 
#endif    
    *this = other;
}

/**
 * @brief Destructor for the Cat class.
 *        Prints a message indicating that the cat is destroyed.
 */        
Cat::~Cat()
{
#ifdef TRACE
    printDestroyMessage(); 
#endif
}

/**
 * @brief Virtual method to print a message indicating that the cat is destroyed.
 */
void Cat::printDestroyMessage() const 
{
    std::cout << _type << " is destroyed." << std::endl;
}

/**
 * @brief Assignment operator overload for the Cat class.
 *        Assigns the type from another Cat object.
 * 
 * @param other The Cat object to assign from.
 * @return Cat& A reference to the assigned Cat object.
 */
Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
#ifdef TRACE
    std::cout << "Animal " << _type << " assignation opeerator is called." << std::endl;   
#endif
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << _type << " Sound: ***Miyyav***" << std::endl;
}