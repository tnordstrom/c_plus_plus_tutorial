/* Tony Nordstrom */
/* January 12 02025 */
/* Chapter 13.6 quiz question 1 */

#include <iostream>
#include <string_view>

enum class Animal
{
	pig,
	chicken,
	goat,
	cat,
    dog,
	duck,
};

constexpr std::string_view getAnimalName(Animal animal)
{
	switch (animal)
	{
		case Animal::pig:
			return "pig";
		case Animal::chicken:
			return "chicken";
		case Animal::goat:
			return "goat";
		case Animal::cat:
			return "cat";
		case Animal::dog:
			return "dog";
		case Animal::duck:
			return "duck";

		default:
			return "invalid";
	}

}

void printNumberOfLegs(Animal animal)
{
	switch (animal)
	{
		case Animal::pig:
			std::cout << 4;
			break;
		case Animal::chicken:
			std::cout << 2;
			break;
		case Animal::goat:
		case Animal::cat:
		case Animal::dog:
			std::cout << 4;
			break;
		case Animal::duck:
			std::cout << 2;
			break;
		default:
			std::cout << "Error";
			break;
	}
}
	
int main ( void )
{
	Animal one { Animal::cat };
	Animal two { Animal::chicken };
	
	std::cout << "A " << getAnimalName(one) << " has ";
	printNumberOfLegs(one);
	std::cout << " legs.\n";
	std::cout << "A " << getAnimalName(two) << " has ";
	printNumberOfLegs(two);
	std::cout << " legs.\n";
	
	
	
	return 0;
}
