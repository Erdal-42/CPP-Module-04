#include "Cat.hpp"

Cat::Cat(void) : AbstractAnimal()
{
#ifdef TRACE
    std::cout << "Cat default constructor called." << std::endl;  
#endif
    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat &other) : AbstractAnimal()
{
#ifdef TRACE
    std::cout << "Cat copy constructor called." << std::endl; 
#endif 
    _brain = NULL;
    *this = other;
}

Cat::~Cat()
{
#ifdef TRACE
    printDestroyMessage(); 
#endif
    delete _brain;
}

void Cat::printDestroyMessage() const 
{
    std::cout << _type << " is destroyed." << std::endl;
}



Cat &Cat::operator=(const Cat &other)
{
#ifdef TRACE
    std::cout << "Cat assignment overload operator called." << std::endl;   
#endif
    if (this != &other)
    {
        _type = other._type;
        if (_brain != NULL)
            delete (_brain);
        _brain = new Brain(*other._brain);
    }

    return (*this);
}

Brain   *Cat::getBrain(void) const
{
    return (_brain);
}

void    Cat::makeSound(void) const
{
    std::cout << _type << " Sound: ***Miyyav***" << std::endl;
}



