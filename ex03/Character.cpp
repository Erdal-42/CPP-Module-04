#include "Character.hpp"

/**
 * @brief Constructs a new Character object with the name set to "Unnamed".
 *        Prints a message indicating that the default constructor is called.
 */
Character::Character(void) : _name("Unnamed")
{
    std::cout << "Character default constructor called." << std::endl;
    _initializeEmptyInventory();
}
/**
 * @brief Here we are copy constructing. To begin with we are initializing
 * the inventory (AMateria *) of the new Character. Then we are 
 * assigning the source "other".
 */
Character::Character(const Character &other)
{
    std::cout << "Character copy constructor called." << std::endl;
    _initializeEmptyInventory();
    *this = other;
}

/**
 * @brief Constructs a new Character object with the specified name.
 *        Prints a message indicating that the constructor is called with the name.
 * 
 * @param name The name of the Character.
 */
Character::Character(const std::string &name) : _name(name)
{
	std::cout << "Character constructor called with name \"" << _name << "\"." << std::endl;   
    _initializeEmptyInventory();
}

/**
 * @brief Destroys the Character object.
 *        Prints a message indicating that the destructor is called for the Character.
 */
Character::~Character(void)
{
    std::cout << "Character destructor called for \"" << _name << "\"." << std::endl;
    _deleteInventory();
}

/**
 * @brief Assigns another Character object to this Character.
 * 
 * @param other The Character object to assign.
 * @return Character& A reference to this Character object after assignment.
 */
Character &Character::operator=(const Character &other)
{
    int i;
    std::cout << "Character assignment operator overload called." << std::endl;
    this->_name = other._name;
    _deleteInventory();

    i = 0;
    while (i < _inventorySize)
    {
        if (other._inventory[i] != NULL) 
            _inventory[i] = other._inventory[i]->clone();                                           
        ++ i;
    }
    return (*this);
}

/**
 * @brief Gets the name of the Character.
 * 
 * @return std::string const& The name of the Character.
 */
std::string const &Character::getName(void) const
{
    return (_name);
}

/**
 * @brief Sets the name of the Character.
 * 
 * @param theName The new name of the Character.
 */
void    Character::setName(const std::string &theName)
{
    _name = theName;
}

/**
 * @brief Equips a Materia to the Character's inventory.
 * Prints a message indicating the Materia is equipped or if 
 * the inventory is full.This function slots the parameter 
 * AMateria * to the Character objects inventory where there 
 * is an available NULL slot. If there is no available NULL 
 * slot, then it does nothing.
 * 
 * @param amateria The AMateria object to equip.
 */
void    Character::equip(AMateria *amateria)
{
    if (!amateria)
    {
        std::cout << _name << ": Can't equip something that doesn't exist!" << std::endl;
		return ;   
    }
    for (int i = 0; i < _inventorySize; i ++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = amateria;
            std::cout <<  _name << " equipped " << amateria->getType() << " materia to inventory index " << i << "." << std::endl;
            return ;
        }
    }
    std::cout << _name << ": I can't carry any more materia!" << std::endl;
}

/**
 * @brief Unequips a Materia from the Character's inventory. Prints a 
 * message indicating the Materia is unequipped or if the index is invalid.
 * 
 * The unequip function is responsible for unequipping a materia from a 
 * specific index in the character's inventory. The unequip function 
 * removes a materia from a specific index in the character inventory by 
 * setting the corresponding element in the _inventory array to NULL.
 * 
 * @param index The index of the Materia to unequip.
 *
 */
void    Character::unequip(int index)
{
    if (index < 0 || index >= _inventorySize)
    {
        std::cout << _name << ": You can't unequip for an invalid index number!" << std::endl;
        return ;
    }
    if (_inventory[index] == NULL)
    {
        std::cout << _name << ": You materia for the given index is already NULL. Can't unequip!" << std::endl;
        return ;
    }
    std::cout << _name << " unequipped " << _inventory[index]->getType()
		<< " materia from inventory index " << index << "." << std::endl;
    _inventory[index] = NULL;
    return ;
}

/**
 * @brief Uses a Materia from the Character's inventory on a target Character.
 *        Prints a message indicating the Materia is used or if the index is invalid.
 *  
 * The use function is responsible for using the materia stored at a specific 
 * index in the character's inventory on a target character.
 * It takes two parameters: an integer index representing the index of the 
 * materia in the inventory to be used and a reference to an Character 
 * object target representing the character on which the materia will be used.
 *
 * @param index The index of the Materia to use.
 * @param target The target Character to use the Materia on.
 */
void    Character::use(int index, ICharacter &target)
{
    if (index < 0 || index >= _inventorySize)
    {
        std::cout << _name << ": You can't use item for invalid index number!" << std::endl;
        return ;
    }
    if (_inventory[index] != NULL)
    {
        std::cout << _name << ": ";
        _inventory[index]->use(target); 
    }
    else
		std::cout << _name << ": I don't have an item in my inventory at index " << index << "!" << std::endl;
}

/**
 * @brief Displays the inventory of the Character.
 *        Prints a message indicating the Materia in each slot of the inventory.
 */
void    Character::displayInventory(void) const
{
	std::cout << _name << "'s inventory contains:" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
	{
		std::cout << "\t[" << i << "] ";
		if (this->_inventory[i] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << _inventory[i]->getType() << " materia.";
		std::cout << std::endl;
	}
	return ;
}

/**
 * @brief Initializes the inventory of the Character to NULL.
 */
void    Character::_initializeEmptyInventory(void)
{
    for (int i = 0; i < _inventorySize; i ++)
        _inventory[i] = NULL;
}

/**
 * @brief Deletes all the Materia objects in the inventory of the Character.
 */
void	Character::_deleteInventory(void)
{
    for (int i = 0; i < _inventorySize; i ++)
    {
        if (_inventory[i] != NULL)
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
}