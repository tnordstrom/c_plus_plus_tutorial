/* Tony Nordstrom */
/* September 21 02024 */
/* Chapter 5 quiz question 5 */

#include <iostream>

int main()
{
	std::cout << "Enter person 1 name: ";
	std::string name1 { };
	std::getline(std::cin >> std::ws, name1);
	
	std::cout << "Enter person 2 name: ";
	std::string name2 { };
	std::getline(std::cin >> std::ws, name2);
	
	std::cout << "Enter age of " << name1 << ": ";
	int age1 { };
	std::cin >> age1;
	
	std::cout << "Enter age of " << name2 << ": ";
	int age2 { };
	std::cin >> age2;
	
	if (age1 < age2)
	{
		std::cout << name2 << " (" << age2 << ") is older than " << name1 << " (" << age1 << ")\n";
	}
	else if (age2 < age1)
	{
		std::cout << name1 << " (" << age1 << ") is older than " << name2 << " (" << age2 << ")\n";
	}
	else
	{
		std::cout << name1 << " and " << name2 << " are the same age (" << age1 << ")\n";
	}
	
	return 0;
}
