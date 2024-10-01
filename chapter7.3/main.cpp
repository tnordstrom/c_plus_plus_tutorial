/* October 1 02024 */
/* Tony Nordstrom */
/* Chapter 7.3 Local Variables */

#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int smaller { };
	std::cin >> smaller;
	
	std::cout << "Enter a larger integer: ";
	int larger { };
	std::cin >> larger;
	
	if (smaller > larger)
	{
		int temp { larger };
		larger = smaller;
		smaller = temp;
		std::cout << "Swapping the values\n";
			
	} // temp dies here
	
	// Using the standard library <utility> header, the first 3 lines of
	// the if block can be replaced with:
	//std::swap(larger, smaller);
	
	std::cout << "The smaller value is " << smaller << '\n';
	std::cout << "The larger value is " << larger << '\n';

	return 0;
} // smaller and larger die here.
