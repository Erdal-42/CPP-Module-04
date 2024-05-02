#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
    //Constructors
        WrongCat(void);
        WrongCat(const WrongCat &);
    
    //Destructors
        ~WrongCat();
        void printDestroyMessage(void) const;
    
    //Overloaded Operators
        WrongCat &operator=(const WrongCat &);
    
    //Public Methods
        void makeSound(void) const;  
};

#endif