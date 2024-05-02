#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain   *_brain;
        
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
        Brain   *getBrain(void) const;
};

#endif