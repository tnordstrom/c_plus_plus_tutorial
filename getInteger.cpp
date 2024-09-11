/* Tony Nordstrom - September 11 02024 */
/* getInteger.cpp */

#include "getInteger.hpp"

#include <iostream>

int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{ };
	std::cin >> x;
	
	return x;
}
