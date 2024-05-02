
#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>

#define TRACE


class WrongAnimal
{
    protected:
        std::string _type;
    public:
    // Constructors
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &);

    //Destructor
        virtual ~WrongAnimal();
        virtual void printDestroyMessage(void) const;

    //Overloaded Operators
        WrongAnimal &operator=(const WrongAnimal &);
            
    //Public Methods
    void makeSound(void) const;

    //Setters
        void        setType(std::string);

    //Getters
        std::string getType(void) const;
};

#endif