/* Tony Nordstrom */
/* February 3 02025 */
/* Chapter 14.3 quiz question 1 & 2 */

#include <iostream>

struct IntPair
{
	int first { 0 };
	int second { 0 };
	
	void print(void)
	{
		std::cout << "Pair(" << first << ", " << second << ")\n";
	}
	
	bool isEqual(const IntPair pair)
	{
		return (first == pair.first) && (second == pair.second);
	}
};
	

int main ( void )
{
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();
	
	std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
}
