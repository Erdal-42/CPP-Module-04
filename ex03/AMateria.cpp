
#include "AMateria.hpp"

/**
 * @brief Constructs a new AMateria object with the type set to "Anonymous".
 *        Prints a message indicating that the default constructor is called.
 */
AMateria::AMateria(void) : _type("Anonymous")
{
	std::cout << "AMateria default constructor called." << std::endl;
}

/**
 * @brief Copy constructs a new AMateria object from another AMateria.
 * 
 * @param other The AMateria object to copy.
 */
AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	std::cout << "AMateria copy constructor called." << std::endl;    
}

/**
 * @brief Constructs a new AMateria object with the specified type.
 *        Prints a message indicating that the type constructor is called.
 * 
 * @param theType The type of the AMateria.
 */
AMateria::AMateria(const std::string &theType) : _type(theType)
{
    std::cout << "AMateria type constructor called." << std::endl;
}

/**
 * @brief Destroys the AMateria object.
 *        Prints a message indicating that the destructor is called.
 */
AMateria::~AMateria(void)
{
    std::cout << "AMateria destructor called." << std::endl;
}

/**
 * @brief Assigns another AMateria object to this AMateria.
 * 
 * @param other The AMateria object to assign.
 * @return AMateria& A reference to this AMateria object after assignment.
 */        
AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria assignment operator overload called." << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

/**
 * @brief Gets the type of the AMateria.
 * 
 * @return std::string const& The type of the AMateria.
 */
std::string const &AMateria::getType() const
{
    return (_type);
}

/* 
 * The use function is a virtual member function of the 
 * AMateria class. It is responsible for using the materia 
 * on a target, represented by an object of type ICharacter.
 */ 
void AMateria::use(ICharacter &target)
{
   	std::cout << "* An unknown materia is being used against" << target.getName() << " *" << std::endl;
}