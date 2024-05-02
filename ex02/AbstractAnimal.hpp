
#ifndef ABSTRACTANIMAL_H
# define ABSTRACTANIMAL_H

#include <iostream>

#define TRACE
/*
 * Virtual functions allow a derived class to override 
 * the implementation of a function in its base class. 
 * This allows for code to be written that can work with 
 * objects of multiple classes, as long as they share a 
 * common interface. 
 * 
 * In summary, virtual functions have a default 
 * implementation in the base class but can be overridden 
 * by derived classes. Pure virtual functions have no 
 * implementation in the base class and must be 
 * overridden by derived classes, making the base class 
 * abstract. It is declared by appending "= 0" to the 
 * function declaration in the base class.
 *
 * A class containing at least one pure virtual function 
 * becomes an abstract class, and objects cannot be created 
 * directly from it. The derived classes of an abstract 
 * class must provide implementations for all pure virtual 
 * functions declared in the base class; otherwise, they 
 * also become abstract classes. Pure or not virtual 
 * functions enable polymorphism.
 */


class AbstractAnimal
{
    protected:
        std::string _type;
    
    public:
    // Constructors
        AbstractAnimal(void);
        AbstractAnimal(const AbstractAnimal &);

    //Destructor
        virtual ~AbstractAnimal();
        void printDestroyMessage(void) const;

    //Overloaded Operators
        AbstractAnimal &operator=(const AbstractAnimal &);
            
    //Public Methods
    virtual void makeSound(void) const = 0;

    //Setters
        void        setType(std::string);

    //Getters
        std::string getType(void) const;
};

#endif