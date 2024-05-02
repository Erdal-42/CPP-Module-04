#include "Animal.hpp"

/**
 * @brief Default constructor for the Animal class.
 *        Initializes the type of the animal to "Anonymous".
 */
Animal::Animal(void) : _type("Anonymous")
{
#ifdef TRACE
    std::cout << "Animal " << _type << " constructed." << std::endl;  
#endif
}

/**
 * @brief Copy constructor for the Animal class.
 *        Copies the type from another Animal object.
 * 
 * @param other The Animal object to copy from.
 */
Animal::Animal(const Animal &other)
{
    *this = other;
#ifdef TRACE
    std::cout << "Animal Copy Constructor called" << std::endl;
#endif
}

/**
 * @brief Destructor for the Animal class.
 *        Prints a message indicating that the animal is destroyed.
 */        
Animal::~Animal()
{
#ifdef TRACE
    printDestroyMessage();  
#endif
}

/**
 * @brief Prints a message indicating that the animal is destroyed.
 */
void Animal::printDestroyMessage() const 
{
    std::cout << "Animal is destroyed." << std::endl;
}

/**
 * @brief Assignment operator overload for the Animal class.
 *        Assigns the type from another Animal object.
 * 
 * @param other The Animal object to assign from.
 * @return Animal& A reference to the assigned Animal object.
 */
Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
#ifdef TRACE
    std::cout << "Animal " << _type << " assignation operator is called." << std::endl;   
#endif
    return (*this);
}

/**
 * @brief Sets the type of the animal.
 * 
 * @param theType The type of the animal.
 */
void    Animal::setType(std::string theType)
{
    _type = theType;
}

/**
 * @brief Gets the type of the animal.
 * 
 * @return std::string The type of the animal.
 */
std::string Animal::getType(void) const
{
    return (_type);
}

/**
 * @brief Makes a sound specific to the type of the animal.
 */
void    Animal::makeSound(void)const
{
    std::cout << _type << " Sound: ***???***" << std::endl;
}