#include "MateriaSource.hpp"


/**
 * @brief Constructs a new AMateria object with the type set to "Anonymous".
 */
MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource default constructor called." << std::endl;
    _initializeEmptyRecipes(); 
}

/**
 * @brief Copy constructs a new AMateria object from another AMateria.
 * 
 * @param other The AMateria object to copy.
 */
MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "MateriaSource copy constructor called." << std::endl;
    _initializeEmptyRecipes();
    *this = other;
}

/**
 * @brief Destroys the AMateria object.
 *        Prints a message indicating that the destructor is called.
 */
MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource destructor called." << std::endl; 
    _deleteRecipes();  
}

/**
 * @brief Assigns another AMateria object to this AMateria.
 * 
 * @param other The AMateria object to assign.
 * @return AMateria& A reference to this AMateria object after assignment.
 */
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "MateriaSource assignment operator overload called." << std::endl;
    _deleteRecipes();
    for (int i=0; i < _maxRecipes; i++)
    {
        if (_recipes[i] != NULL)
            _recipes[i] = other._recipes[i]->clone();
    }
    return (*this);
}


/**
 * @brief The learnMateria function is responsible for learning a new AMateria 
 * and storing it for later use.
 * Here's how the function works: It receives an AMateria* pointer named 
 * materia as a parameter, representing the materia to be learned.
 * It first checks if the materia pointer is valid (i.e., not NULL). 
 * If it is NULL, it outputs an error message and returns.
 * It then iterates over the _recipes array, which stores the learned 
 * materias.
 * If an empty slot is found in the _recipes array (indicated by a NULL 
 * value), the materia pointer is assigned to that slot, indicating 
 * that the materia has been learned.
 * The learnMateria function allows the MateriaSource to keep track of 
 * learned materias, which can later be cloned using the createMateria 
 * function.
 */ 
void MateriaSource::learnMateria(AMateria *materia)
{
    if (!materia)
    {
        std::cout << "MateriaSource was not provided with a materia to learn." << std::endl;
        return ;
    }
    for (int i=0; i < _maxRecipes; i++)
    {
        if (_recipes[i] == NULL)
        {
            _recipes[i] = materia;
            std::cout << "MateriaSource learned the " << materia->getType() << " materia recipe." << std::endl;
			return ; 
        }
    }
    std::cout << "MateriaSource can't learn any more materia." << std::endl;
	delete materia;
	return ;
}

/**
 * @brief The purpose of the createMateria function is to create a new 
 * instance of a Materia object based on the type provided as a parameter.
 * 
 * Basically createMateria function creates a new Materia object by cloning a 
 * previously learned Materia of the specified type (a recipe whos type matches
 * the parameter). If the MateriaSource does not know the type (cant match the 
 * type with those in the recipe), it returns a null pointer.
 */ 
 AMateria* MateriaSource::createMateria(std::string const &type)
 {
    for (int i=0; i < _maxRecipes; i++)
    {
        if (_recipes[i] && _recipes[i]->getType() == type)
        {
            std::cout << "MateriaSource creating " << type << " materia." << std::endl;
            return (_recipes[i]->clone());
        }
    }
    std::cout << "MateriaSource does not know the type \"" << type << "\"." << std::endl;
    return (NULL);
 }

/**
 * @brief Initializes the recipes of the MateriaSource to NULL.
 */
void    MateriaSource::_initializeEmptyRecipes(void)
{
    for (int i=0; i < _maxRecipes; i++)
    {
        _recipes[i] = NULL;
    }
}

/**
 * @brief Deletes all the AMateria objects in the recipes of the MateriaSource.
 */
void    MateriaSource::_deleteRecipes(void)
{
    for (int i=0; i < _maxRecipes; i++)
    {
        if (_recipes[i] != NULL)
        {
            delete _recipes[i];
            _recipes[i] = NULL;
        }
    }
}

/**
 * @brief Displays the known recipes of the MateriaSource.
 *        Prints a message indicating each known recipe.
 */
void    MateriaSource::displayKnownRecipes(void)
{
    std::cout << "MateriaSource knows the following recipes:" << std::endl;
    for (int i=0; i < _maxRecipes; i++)
    {
        std::cout << "\t" << i << ". ";
        if (_recipes[i] == NULL)
            std::cout << "Empty slot.";
        else
            std::cout << _recipes[i]->getType() << " materia.";
        std::cout << std::endl;
    }
    return ;
}