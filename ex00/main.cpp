#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void    test_animal()
{
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "\033[44mConstructing\033[0m" << std::endl;
	Animal	animal;
	std::cout << std::endl;
	std::cout << "\033[44mTesting\033[0m" << std::endl;

	std::cout << "Animal Type: " << animal.getType() << std::endl;
	animal.makeSound();
	std::cout << std::endl;

	std::cout << "\033[44mDeconstructing\033[0m" << std::endl;
}

void    test_cat()
{
    std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "\033[44mConstructing\033[0m" << std::endl;
	const Cat	cat;
	std::cout << std::endl;
	std::cout << "\033[44mTesting\033[0m" << std::endl;

	std::cout << "Cat Type: " << cat.getType() << std::endl;
	cat.makeSound();
	std::cout << std::endl;

	std::cout << "\033[44mDeconstructing\033[0m" << std::endl;
}

void    test_dog()
{
    std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "\033[44mConstructing\033[0m" << std::endl;
	Dog	dog;
	std::cout << std::endl;
	std::cout << "\033[44mTesting\033[0m" << std::endl;

	std::cout << "Dog Type: " << dog.getType() << std::endl;
	dog.makeSound();
	std::cout << std::endl;

	std::cout << "\033[44mDeconstructing\033[0m" << std::endl;
}

void    test_wronganimal()
{
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "\033[44mConstructing\033[0m" << std::endl;
	WrongAnimal	wronganimal;
	std::cout << std::endl;
	std::cout << "\033[44mTesting\033[0m" << std::endl;

	std::cout << "WrongAnimal Type: " << wronganimal.getType() << std::endl;
	wronganimal.makeSound();
	std::cout << std::endl;

	std::cout << "\033[44mDeconstructing\033[0m" << std::endl;
}

void	test_wronganimal_cat()
{
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "\033[44mConstructing\033[0m" << std::endl;
/* Effectively, by using the derived class constructor WrongCat(), we create an 
 * object of type WrongCat that is treated as a WrongAnimal object through the base 
 * class pointer beast. This is possible due to polymorphism, where a derived class 
 * object can be treated as an object of its base class.
 *
 * This approach allows you to use the base class pointer beast to access the common 
 * interface and member functions defined in the WrongAnimal class, while still 
 * preserving the ability to utilize any additional functionality or behavior specific 
 * to the WrongCat class if needed.
 */
	WrongAnimal *beast = new WrongCat();
	std::cout << std::endl;
	std::cout << "\033[44mTesting\033[0m" << std::endl;
	std::cout << "WrongCat Type: " << beast->getType() << std::endl;
	beast->makeSound();
	std::cout << std::endl;

	std::cout << "\033[44mDeconstructing\033[0m" << std::endl;
	delete beast;
}

void    test_wrongcat()
{
    std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "\033[44mConstructing\033[0m" << std::endl;
	const WrongCat	wrongcat;
	std::cout << std::endl;
	std::cout << "\033[44mTesting\033[0m" << std::endl;

	std::cout << "WrongCat Type: " << wrongcat.getType() << std::endl;
	wrongcat.makeSound();
	std::cout << std::endl;

	std::cout << "\033[44mDeconstructing\033[0m" << std::endl;
}

int main()
{
    test_animal();
    test_cat();
    test_dog();

	test_wronganimal();
	test_wronganimal_cat();
    test_wrongcat();

    return (0);
}

