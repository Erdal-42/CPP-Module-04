#ifndef DOG_H
# define DOG_H

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Dog : public AbstractAnimal
{
    private:
        Brain   *_brain;

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
        Brain   *getBrain(void) const;
};

#endif