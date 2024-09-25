/* September 25 02024 */
/* Tony Nordstrom */
/* Chapter O.2 Question 2 & 3 */

#include <bitset>
#include <iostream>

#undef QUESTION_2

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
#ifdef QUESTION_2
	if (bits.test(3))
#else
	const std::bitset<4> bitmask {0b1000};
	
	if ((bits & bitmask) == bitmask) 
#endif
	{
		bits <<= 1;
		bits |= 0b0001;
	}
	else
	{
		bits <<= 1;
	}

	return bits;
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}
