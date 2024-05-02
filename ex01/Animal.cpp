#include "Animal.hpp"

Animal::Animal(void) : _type("Anonymous")
{
#ifdef TRACE
    std::cout << "Animal " << _type << " constructed." << std::endl;  
#endif
}

Animal::Animal(const Animal &other)
{
    *this = other;
#ifdef TRACE
    std::cout << "Animal Copy Constructor called" << std::endl;
#endif
}
        
Animal::~Animal()
{
#ifdef TRACE
    printDestroyMessage();  
#endif
}

void Animal::printDestroyMessage() const 
{
    std::cout << "Animal is destroyed." << std::endl;
}

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

void    Animal::setType(std::string theType)
{
    _type = theType;
}

std::string Animal::getType(void) const
{
    return (_type);
}

void    Animal::makeSound(void)const
{
    std::cout << _type << " Sound: ***???***" << std::endl;
}