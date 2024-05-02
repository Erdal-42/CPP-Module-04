
#ifndef CHARACTER_H
# define CHARACTER_H

# include "AMateria.hpp"
# include "ICharacter.hpp"
                            

class Character : public ICharacter
{
    private:
		  static int const	_inventorySize = 4;
		  std::string	_name;
		  AMateria *_inventory[_inventorySize];
		  void	_initializeEmptyInventory(void); 
		  void	_deleteInventory(void);

    public:
        Character(void);
        Character(const Character &);
        Character(const std::string &);
        ~Character(void);

        Character   &operator=(const Character &);

        std::string const   &getName(void) const;
        void                setName(const std::string &);
        void                equip(AMateria *);
        void                unequip(int);
        void                use(int, ICharacter &);
        void	 			displayInventory(void) const;
};

#endif