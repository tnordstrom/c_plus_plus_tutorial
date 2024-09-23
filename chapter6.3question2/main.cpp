/* September 23 02024 */
/* Tony Nordstrom */
/* Chapter 6.3 Question 2 */

#include <iostream>

constexpr bool isEven(int val)
{
	return (val % 2) ? false : true; 
}

int main()
{
	
	std::cout << "Enter an integer: ";
	int val { };
	std::cin >> val;
	
	std::cout << val << (isEven(val) ? " is even\n" : " is odd\n");

	return 0;
	
}
