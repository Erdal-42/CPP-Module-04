#include "WrongCat.hpp"

/**
 * @brief Constructs a new WrongCat object.
 *        Initializes the type of the WrongCat to "WrongCat".
 */
WrongCat::WrongCat(void) : WrongAnimal()
{
    _type = "WrongCat";
#ifdef TRACE
    std::cout << _type << " constructed." << std::endl;  
#endif
}

/**
 * @brief Copy constructs a new WrongCat object from another WrongCat.
 * 
 * @param other The WrongCat object to copy.
 */
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
    *this = other;
#ifdef TRACE
    std::cout << _type << " copy constructed." << std::endl;
#endif
}

/**
 * @brief Destroys the WrongCat object.
 *        Prints a message indicating that the WrongCat is destroyed.
 */  
WrongCat::~WrongCat()
{
#ifdef TRACE
    printDestroyMessage();  
#endif
}


/**
 * @brief Prints a message indicating that the WrongCat is destroyed.
 */
void WrongCat::printDestroyMessage() const 
{
    std::cout << _type << " is destroyed." << std::endl;
}

/**
 * @brief Assigns another WrongCat object to this WrongCat.
 * 
 * @param other The WrongCat object to assign.
 * @return WrongCat& A reference to this WrongCat object after assignment.
 */
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
#ifdef TRACE
    std::cout << "WrongCat " << _type << " assignation operator is called." << std::endl;   
#endif
    return (*this);
}

/**
 * @brief Makes a sound characteristic of the WrongCat.
 *        Prints a message to the standard output indicating the sound.
 */
void    WrongCat::makeSound(void) const
{
    std::cout << _type << " Sound: ***WrongCat Sound***" << std::endl;
}