/* Tony Nordstrom */
/* November 25 02024 */
/* Chapter 11.x quiz question 2 */

#include <iostream>

template <typename T>
T add(T x, T y)
{
	return (x + y);
}

template <typename T>
T mult(T x, int y)
{
	return (x * y);
}

template <typename T, typename U>
auto sub(T x, U y)
{
	return (x - y);
}

int main ( void )
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';
   
	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';
	
	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';
	
	return 0;
}

