#include "AbstractAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define NUMBER_ANIMALS 4

void	testAnimalArray(void)
{
	std::cout <<  "-------------------------------" << std::endl
		<< "\tABSTRACT ANIMAL ARRAY TEST" << std::endl
		<<  "-------------------------------" << std::endl << std::endl;
	AbstractAnimal	* animalArray[NUMBER_ANIMALS + 1];
	animalArray[NUMBER_ANIMALS] = NULL;

	std::cout << "-- Creating a kennel of " << NUMBER_ANIMALS << " abstract animals: " 
		<< NUMBER_ANIMALS / 2 << " cats and "
		<< NUMBER_ANIMALS - (NUMBER_ANIMALS / 2) << " dogs." << std::endl;

	for (int i = 0; i < NUMBER_ANIMALS / 2; i++)
	{
		std::cout << i+1 << ". ";
		animalArray[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = NUMBER_ANIMALS / 2; i < NUMBER_ANIMALS; i++)
	{
		std::cout << i+1 << ". ";
		animalArray[i] = new Dog();
	}
	std::cout << std::endl << "-- The cats and dogs are loud..." << std::endl;
	for (int i = 0; animalArray[i]; i++)
	{
		std::cout << i+1 << ". ";
		animalArray[i]->makeSound();
	}
	std::cout << std::endl << "-- Destroy the loud animals!"<< std::endl;
	for (int i = 0; animalArray[i]; i++)
	{
		std::cout << i+1 << ". ";
		delete animalArray[i];
	}
	std::cout << std::endl;
}

void testCopyCat(void)
{
	std::cout <<  "-------------------------------" << std::endl
		<< "\tCOPY CAT TEST" << std::endl
		<<  "-------------------------------" << std::endl << std::endl
		<< "-- Creating \"Angora\" cat." << std::endl;
	Cat *angora = new Cat();

	std::cout << std::endl << "-- Putting ideas in Angora's brain..." << std::endl;
	angora->getBrain()->setIdea(0, "I slept well...");
	angora->getBrain()->setIdea(1, "..think I should roll over. ...yawn.");
	angora->getBrain()->setIdea(2, "Back to sleep..");

	std::cout << "Angora idea 1: \"" << angora->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "Angora idea 2: \"" << angora->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "Angora idea 3: \"" << angora->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "-- Creating a copy of \"Angora\" cat" << std::endl;
	Cat *copyCat = new Cat(*angora);

	std::cout << std::endl << "-- CopyCat should have the same ideas as Angora." << std::endl;
	std::cout << "CopyCat idea1: \"" << copyCat->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea2: \"" << copyCat->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "CopyCat idea3: \"" << copyCat->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "-- Putting new ideas in Angora's brain..." << std::endl;
	angora->getBrain()->setIdea(0, "Where is that mouse??");
	angora->getBrain()->setIdea(1, "I'm hungry.");
	angora->getBrain()->setIdea(2, "..I hope that mouse walks into my mouth.");

	std::cout << "Angora idea 0: \"" << angora->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "Angora idea 1: \"" << angora->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "Angora idea 2: \"" << angora->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "-- CopyCat's ideas should not have changed." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyCat->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyCat->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "CopyCat idea2: \"" << copyCat->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "-- Setting CopyCat = Angora." << std::endl;
	*copyCat = *angora;

	std::cout << std::endl << "-- CopyCat's ideas should have changed to Angora's." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyCat->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyCat->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "CopyCat idea2: \"" << copyCat->getBrain()->getIdea(2) << "\"" << std::endl;


	std::cout << std::endl << "-- Deleting Angora and CopyCat. --" << std::endl;
	delete angora;
	delete copyCat;
	std::cout << std::endl;
}

void testCopyDog(void)
{
	std::cout <<  "-------------------------------" << std::endl
		<< "\tCOPY DOG TEST" << std::endl
		<<  "-------------------------------" << std::endl << std::endl
		<< "-- Creating \"kangal\" dog" << std::endl;
	Dog * kangal = new Dog();
	std::cout << std::endl << "-- Putting ideas in kangal's brain..." << std::endl;
	kangal->getBrain()->setIdea(0, "Food! Food! Food!");
	kangal->getBrain()->setIdea(1, "Human! Human! Human!");

	std::cout << "kangal idea 0: \"" << kangal->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "kangal idea 1: \"" << kangal->getBrain()->getIdea(1) << "\"" << std::endl;

	std::cout << std::endl << "-- Creating a copy of \"kangal\" dog." << std::endl;
	Dog * copyDog = new Dog(*kangal);
	
	std::cout << std::endl << "-- CopyDog should have the same ideas as kangal." << std::endl;
	std::cout << "CopyDog idea0: \"" << copyDog->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyDog idea1: \"" << copyDog->getBrain()->getIdea(1) << "\"" << std::endl;
	
	std::cout << std::endl << "-- Putting new ideas in kangal's brain..." << std::endl;
	kangal->getBrain()->setIdea(0, "Fetch! Fetch! Fetch!");
	kangal->getBrain()->setIdea(1, "Bark! Bark! Bark!");

	std::cout << "kangal idea 0: \"" << kangal->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "kangal idea 1: \"" << kangal->getBrain()->getIdea(1) << "\"" << std::endl;
	
	std::cout << std::endl << "-- CopyDog's ideas should not have changed." << std::endl;
	std::cout << "CopyDog idea0: \"" << copyDog->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyDog idea1: \"" << copyDog->getBrain()->getIdea(1) << "\"" << std::endl;

	std::cout << std::endl << "-- Setting CopyDog = kangal." << std::endl;
	*copyDog = *kangal;

	std::cout << std::endl << "-- CopyDog's ideas should have changed to kangal's." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyDog->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyDog->getBrain()->getIdea(1) << "\"" << std::endl;

	std::cout << std::endl << "-- Deleting kangal and CopyDog." << std::endl;
	delete kangal;
	delete copyDog;
	std::cout << std::endl;
}

int	main(void)
{
	testAnimalArray();
	testCopyCat();
//	testCopyDog();

	return (0);
}
