
#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>
#include <iostream>
#include "ICharacter.hpp"


/* 
 * The term "concrete class" is used to refer to any class 
 * that can be instantiated directly, meaning it is not an 
 * abstract class or a pure interface. class   ICharacter is 
 * a forward declaration.
 */

class   ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria(void);
        AMateria(const AMateria &);
        AMateria(const std::string &);
        virtual ~AMateria(void);

        AMateria &operator=(const AMateria &);

        std::string const & getType(void) const;
        virtual AMateria* clone(void) const = 0;
        virtual void use(ICharacter &target);
};

#endif