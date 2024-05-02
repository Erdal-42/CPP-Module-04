
#include "Cure.hpp"

/**
 * @brief Constructs a new Cure object, which is a type of AMateria, with the type set to "cure".
 *        Prints a message indicating that the default constructor is called.
 */
Cure::Cure(void) : AMateria("cure")
{
    std::cout << "Cure default constructor called." << std::endl;
}

/**
 * @brief Copy constructs a new Cure object from another Cure.
 * 
 * @param other The Cure object to copy.
 */
Cure::Cure(const Cure &other) : AMateria("cure")
{
    std::cout << "Cure copy constructor called." << std::endl;
    *this = other;
}

/**
 * @brief Destroys the Cure object.
 *        Prints a message indicating that the destructor is called.
 */
Cure::~Cure(void)
{
    std::cout << "Cure destructor called." << std::endl;
}

/**
 * @brief Assigns another Cure object to this Cure.
 * 
 * @param other The Cure object to assign.
 * @return Cure& A reference to this Cure object after assignment.
 */
Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Cure assignment operator called." << std::endl;
    _type = other._type;
    return (*this);
}


/**
 * @brief Clones the Cure object, creating a new instance of Cure.
 * 
 * @return AMateria* A pointer to the new instance of Cure.
 */
AMateria *Cure::clone(void) const
{
    return (new Cure());
}

/** 
 * @brief This function is a virtual member function of the AMateria 
 * class. It is responsible for using the materia on an ICharacter target. 
 * This function operates by using the AMateria object it is related to on 
 * the ICharacter object provided as a parameter. Since the function is 
 * virtual, derived class functions can update its functionality. 
 *
 */ 
void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;   
}