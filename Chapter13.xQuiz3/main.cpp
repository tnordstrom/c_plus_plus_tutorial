/* Tony Nordstrom */
/* January 27 02025 */
/* Chapter 13.x quiz question 3 */
/* Ref: Chapter 13.13 Class Templates */

#include <iostream>

template <typename T>
struct Triad
{
	T first{};
	T second{};
	T third{};
};

/* Deduction guide for C++17 */
template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
void print(const Triad<T>& data)
{
	std::cout << '[' << data.first << ", " << data.second << ", " << data.third << "]\n";
	
	return;
}

int main ( void )
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}
