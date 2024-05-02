#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain   *_brain;
        //std::string _type;
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