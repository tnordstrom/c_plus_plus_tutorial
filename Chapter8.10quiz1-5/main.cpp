/* Tony Nordstrom */
/* October 22 02024 */
/* Chapter 8.10 quiz questions */

#include <iostream>

#if 0 // Question #1
int main()
{
	for (int i { 0 }; i <= 20; i += 2)
	{
		std::cout << i << ' ';
	}
	
	std::cout << '\n';
		
    return 0;
}
#endif

#if 0 // Question #2
int sumTo(int value)
{
	int sum { 0 };
	
	for (int i { 1 }; i <= value; i++)
	{
		sum += i;
	}
	
	return sum;
}		

int main()
{
	int i { 1 };
	
	while (i <= 10)
	{
		std::cout << "sumTo(" << i << ") = " << sumTo(i) << '\n';
		i++;
	}
	
	return 0;
}
#endif

#if 1 // Question #4, 5
void fizzbuzz(int count)
{
	for (int i { 1 }; i <= count; i++)
	{
		bool printnum { true };
			
		if (i % 3 == 0)
		{
			std::cout << "fizz";
			printnum = false;
		}
		if (i % 5 == 0)
		{
			std::cout << "buzz";
			printnum = false;
		}
		if (i % 7 == 0)
		{
			std::cout << "pop";
			printnum = false;
		}
		if (printnum)
		{
			std::cout << i << '\n';
		}
		else
		{
			std::cout << '\n';
		}
	}
}

int main()
{
	fizzbuzz(150);
	
	return 0;
}
#endif
