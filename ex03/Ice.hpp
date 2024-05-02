#ifndef ICE_MATERIA_H
# define ICE_MATERIA_H

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(const Ice &);
        ~Ice(void);
        
        Ice &operator=(const Ice &);

        AMateria *clone(void) const;
        void use(ICharacter &);
};

#endif