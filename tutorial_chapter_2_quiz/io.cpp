/* Tony Nordstrom - September 12 02024 */
/* Chapter 2 quiz */

#include "io.h"

#include <iostream>

int readNumber(void)
{
	std::cout << "Enter an integer: ";
	int val{ };
	std::cin >> val;
	
	return(val);
}

void writeAnswer(int num)
{
	std::cout << "The number is: " << num << '\n';
	
	return;
}
