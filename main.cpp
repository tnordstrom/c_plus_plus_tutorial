/* Tony Nordstrom - September 11 02024 */
#include <iostream>
#include "getInteger.hpp"

int main()
{
	int x{ getInteger() };
	int y{ getInteger() };
	
	std::cout << x << " + " << y << " is " << x + y << '\n';
	return 0;
}
