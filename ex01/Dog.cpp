#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
#ifdef TRACE
    std::cout << "Dog default constructor called." << std::endl;  
#endif
    _type = "Dog";
    _brain = new Brain;
}

Dog::Dog(const Dog &other) : Animal()
{
#ifdef TRACE
    std::cout << "Dog copy constructor called." << std::endl; 
#endif
    _brain = NULL;
    *this = other;
}

Dog::~Dog()
{
#ifdef TRACE
    printDestroyMessage();  
#endif
    delete _brain;
}

void Dog::printDestroyMessage() const 
{
    std::cout << _type << " is destroyed." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
#ifdef TRACE
    std::cout << "Dog assignment overload operator called."<< std::endl;  
#endif
    if (this != &other)
    {
        _type = other._type;
        if (_brain != NULL)
            delete _brain;
        _brain = new Brain(*other._brain);
    }
    return (*this);
}

Brain   *Dog::getBrain(void) const
{
    return (_brain);
}

void    Dog::makeSound(void) const
{
    std::cout << _type << " Sound: ***VuFF***" << std::endl;
}



