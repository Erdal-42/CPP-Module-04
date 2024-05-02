#include "WrongAnimal.hpp"

/**
 * @brief Default constructor for the WrongAnimal class.
 *        Initializes the type of the animal to "Anonymous".
 */
WrongAnimal::WrongAnimal(void) : _type("Anonymous") 
{
#ifdef TRACE
    std::cout << "WrongAnimal " << _type << " constructed." << std::endl;  
#endif
}

/**
 * @brief Copy constructor for the WrongAnimal class.
 *        Copies the type from another WrongAnimal object.
 * 
 * @param other The WrongAnimal object to copy from.
 */
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
#ifdef TRACE
    std::cout << "WrongAnimal copy constructed." << std::endl;  
#endif
}

/**
 * @brief Destructor for the WrongAnimal class.
 *        Prints a message indicating that the animal is destroyed.
 */     
WrongAnimal::~WrongAnimal()
{
#ifdef TRACE
    printDestroyMessage(); 
#endif
}

/**
 * @brief Virtual method to print a message indicating that the animal is destroyed.
 */
void WrongAnimal::printDestroyMessage() const 
{
    std::cout << "WrongAnimal is destroyed." << std::endl;
}

/**
 * @brief Assignment operator overload for the WrongAnimal class.
 *        Assigns the type from another WrongAnimal object.
 * 
 * @param other The WrongAnimal object to assign from.
 * @return WrongAnimal& A reference to the assigned WrongAnimal object.
 */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
#ifdef TRACE
    std::cout << "WrongAnimal " << _type << " assignation operator is called." << std::endl;   
#endif
    return (*this);
}

/**
 * @brief Sets the type of the WrongAnimal.
 * 
 * @param theType The type to set for the WrongAnimal.
 */
void    WrongAnimal::setType(std::string theType)
{
    _type = theType;
}

/**
 * @brief Gets the type of the WrongAnimal.
 * 
 * @return std::string The type of the WrongAnimal.
 */
std::string WrongAnimal::getType(void) const
{
    return (_type);
}

/**
 * @brief Makes a sound characteristic of the WrongAnimal.
 *        Prints a message to the standard output indicating the sound.
 */
void    WrongAnimal::makeSound(void)const
{
    std::cout << _type << " Sound: ***WrongAnimal Sound***" << std::endl;
}