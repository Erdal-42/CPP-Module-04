
#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>
#include <string>

#define CAPACITY 100 

class Brain
{
    private:
        std::string _ideas[CAPACITY];
    
    public:
        //Constructors
        Brain(void);
        Brain(const Brain &);

        //Destructor
        ~Brain();

        //Overloaded Operators
        Brain &operator=(const Brain &);

        //Getters
        std::string const &getIdea(int index) const;

        //Setters
        void    setIdea(int, const std::string &);
};

#endif