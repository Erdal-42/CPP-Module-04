#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        static int const _maxRecipes = 4;
        AMateria *_recipes[_maxRecipes];
        void    _initializeEmptyRecipes(void);
        void    _deleteRecipes(void);    
    
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &);
        ~MateriaSource(void);

        MateriaSource &operator=(const MateriaSource &);

        void learnMateria(AMateria *);
        AMateria* createMateria(std::string const &);
        void displayKnownRecipes(void);
};

#endif
