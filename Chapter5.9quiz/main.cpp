/* September 17 02024 */
/* Tony Nordstrom */
/* Chapter 5.9 Quiz Question 1 */

#include <iostream>
#include <string>

int main()
{
	std::string name{ };
	std::cout << "Enter your full name: ";
	std::getline(std::cin >> std::ws, name);
	
	int age{ };
	std::cout << "Enter your age: ";
	std::cin >> age;
	
	std::cout << "Your name is: " << name << '\n';
	std::cout << "Your age is: " << age << '\n';
	std::cout << "Your name length + age is: " << (static_cast<int>(name.length())) + age << '\n';
	
	return 0;
}
