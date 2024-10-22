/* Tony Nordstrom */
/* October 21 02024 */
/* Chapter 8.8 quiz question 2 */

#include <iostream>

int main ( void )
{
	char ch { 'a' };
	
	while ( ch <= 'z' )
	{
		std::cout << "character " << ch << " is ASCII " << static_cast<int>(ch) << '\n';
		
		ch++;
	}

	return 0;
	
}
