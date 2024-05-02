
#ifndef ICHARACTER_H
# define ICHARACTER_H


/*
 * This function has been declared how ever its definition 
 * can wait. protoypes for the class AMateria will be sufficient
 * for compilation and informing on the input paraters and output
 * results.
 */

class AMateria;


class ICharacter
{
    public:
        virtual ~ICharacter() {};
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif

