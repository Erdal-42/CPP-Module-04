#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
    public:
    //Constructors
        Cat(void);
        Cat(const Cat &);
    
    //Destructors
        ~Cat();
        void printDestroyMessage(void) const;
    
    //Overloaded Operators
        Cat &operator=(const Cat &);
    
    //Public Methods
        void makeSound(void) const;  
};

#endif