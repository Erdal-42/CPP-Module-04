
#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

#define TRACE
/*
 * run-time polymorphism is achieved through virtual 
 * functions and inheritance. Virtual functions allow 
 * a derived class to override the implementation of a 
 * function in its base class. This allows for code to 
 * be written that can work with objects of multiple 
 * classes, as long as they share a common interface. 
 * Polymorphism is a powerful tool that enables code 
 * reusability and flexibility in object-oriented 
 * programming.
 */

class Animal
{
    protected:
        std::string _type;
    
    public:
    // Constructors
        Animal(void);
        Animal(const Animal &);

    //Destructor
        virtual ~Animal() = 0;
        virtual void printDestroyMessage(void) const;

    //Overloaded Operators
        Animal &operator=(const Animal &);
            
    //Public Methods
    virtual void makeSound(void) const;

    //Setters
        void        setType(std::string);

    //Getters
        std::string getType(void) const;
};

#endif