/* September 26 02024 */
/* Tony Nordstrom */
/* Chapter O.4 Question 6 */

#include <iostream>
#include <cstdint>
#include <bitset>

void printBit(int x, int pow)
{
	std::cout << ((x / pow) % 2);
}

void print8BitBinary(int x)
{
	printBit(x, 128);
	printBit(x, 64);
	printBit(x, 32);
	printBit(x, 16);
	
	std::cout << ' ';
	
	printBit(x, 8);
	printBit(x, 4);
	printBit(x, 2);
	printBit(x, 1);
}

int main()
{
	std::cout << "Enter an integer between 0 and 255: ";
	int val { };
	std::cin >> val;
	
	std::cout << "You entered: " << val << '\n';

	//std::uint8_t binval { static_cast<std::uint8_t>(val) };
	
	// This won't work: there is no std::bin - see 5.3 Outputting values in binary
	//std::cout << std::bin << "In binary that's: " << binval << '\n';
	// And the question says not to use std::bitset or any bitwise operators.
	// The solution is pretty brute-force, I don't think I'd ever do it that way
	// Using ((x / pow) % 2);
	// Why not use the standard libraries if they're available?
	
	// Alex's way
	print8BitBinary(val);
	
	std::cout << '\n';
		
	// This is how I would do it
#if 0
	std::bitset<8> binval { static_cast<std::bitset<8>>(val) };
	std::cout << binval << '\n';
	// or, remove the temporary binval variable
#else
	std::cout << static_cast<std::bitset<8>>(val) << '\n';
#endif
	// Oh but then you don't get the space between the nibbles, big deal
	// My way seems more efficient and leverages the standard library, probably 
	// closer to standard practice. Who needs nibble delimiting? Isn't there a way
	// of getting '-delimiters in bitfields? Check 5.3. I can see input, not output.
	
    return 0;
}
