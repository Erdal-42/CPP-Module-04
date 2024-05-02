#ifndef CURE_MATERIA_H
# define CURE_MATERIA_H

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure(const Cure &);
        ~Cure(void);
        Cure &operator=(const Cure &);
        AMateria *clone(void) const;
        void use(ICharacter &);
};

#endif