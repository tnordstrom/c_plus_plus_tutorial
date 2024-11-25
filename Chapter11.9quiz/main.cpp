/* Tony Nordstrom */
/* November 25 02024 */
/* Chapter 11.9 quiz question 1 */

#include <iostream>

template <int N>
constexpr int factorial()
{
	static_assert(N >= 0);
	
	int product { 1 };
	
	for (int i { 2 }; i <= N; i++)
	{
		product *= i;
	}
	
	return(product);
}

int main ( void )
{
	static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    factorial<-3>(); // should fail to compile
    
	return 0;
}

/*
tonyn@RDFW-W-006 /cygdrive/c/dev/c++/Chapter11.9quiz
$ g++ -Wall -o "main" "main.cpp"
main.cpp: In instantiation of ‘constexpr int factorial() [with int N = -3]’:
main.cpp:28:18:   required from here
main.cpp:10:25: error: static assertion failed
   10 |         static_assert(N >= 0);
      |                       ~~^~~~
main.cpp:10:25: note: the comparison reduces to ‘(-3 >= 0)’
*/
