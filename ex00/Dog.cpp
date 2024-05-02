#include "Dog.hpp"

/**
 * @brief Default constructor for the Dog class.
 *        Initializes the type of the dog to "Dog".
 */
Dog::Dog(void) : Animal()
{
    _type = "Dog";
#ifdef TRACE
    std::cout << _type << " constructed." << std::endl;  
#endif
}

/**
 * @brief Copy constructor for the Dog class.
 *        Copies the type from another Dog object.
 * 
 * @param other The Dog object to copy from.
 */
Dog::Dog(const Dog &other) : Animal()
{
    *this = other;
#ifdef TRACE
    std::cout << "Animal " << _type << " is copy constructed." << std::endl;  
#endif
}

/**
 * @brief Destructor for the Dog class.
 *        Prints a message indicating that the dog is destroyed.
 */        
Dog::~Dog()
{
#ifdef TRACE
    printDestroyMessage();  
#endif
}

/**
 * @brief Virtual method to print a message indicating that the dog is destroyed.
 */
void Dog::printDestroyMessage() const 
{
    std::cout << _type << " is destroyed." << std::endl;
}

/**
 * @brief Assignment operator overload for the Dog class.
 *        Assigns the type from another Dog object.
 * 
 * @param other The Dog object to assign from.
 * @return Dog& A reference to the assigned Dog object.
 */
Dog &Dog::operator=(const Dog &other)
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

/**
 * @brief Makes a sound specific to the dog.
 */
void    Dog::makeSound(void) const
{
    std::cout << _type << " Sound: ***VuFF***" << std::endl;
}