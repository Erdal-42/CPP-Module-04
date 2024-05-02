#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
    public:
    //Constructors
        Dog(void);
        Dog(const Dog &);
    
    //Destructors
        ~Dog();
        void printDestroyMessage(void) const;
    
    //Overloaded Operators
        Dog &operator=(const Dog &);

    //Public Methods
        void makeSound(void) const; 
};


#endif