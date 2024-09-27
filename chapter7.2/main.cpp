/* September 27 02024 */
/* Tony Nordstrom */
/* Chapter 7.2 Namespaces */

#include <iostream>

namespace Big
{
	int hello(int x);

	int hello(int x)
	{
		std::cout << x << " is the value\n";
	
		return 0;
	}
}

namespace Little
{
	int hello(int x);

	int hello(int x)
	{
		std::cout << x << " your number\n";
		
		return 0;
	}
}

int main()
{
	namespace Version = Big;
	
	Big::hello(5);
	Big::hello(6);
	
	Version::hello(10);
	Version::hello(12);
	
	Little::hello(100);
	Little::hello(102);
	
#if 0
	Version = Little; // Apparently you can't reassign a namespace alias
#endif

	Version::hello(1000);
	Version::hello(1001);
}
