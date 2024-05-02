#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal(void) : _type("Anonymous")
{
#ifdef TRACE
    std::cout << "AbstractAnimal " << _type << " constructed." << std::endl;  
#endif
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &other)
{
    *this = other;
#ifdef TRACE
    std::cout << "AbstractAnimal Copy Constructor called" << std::endl;
#endif
}
       
AbstractAnimal::~AbstractAnimal()
{
#ifdef TRACE
    printDestroyMessage();  
#endif
}


void AbstractAnimal::printDestroyMessage() const 
{
    std::cout << "Animal is destroyed." << std::endl;
}


AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
#ifdef TRACE
    std::cout << "AbstractAnimal " << _type << " assignation operator is called." << std::endl;   
#endif
    return (*this);
}

void    AbstractAnimal::setType(std::string theType)
{
    _type = theType;
}

std::string AbstractAnimal::getType(void) const
{
    return (_type);
}
