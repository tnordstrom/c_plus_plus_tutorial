/* Tony Nordstrom */
/* October 28 02024 */
/* Chapter 8.x quiz question 2 */

// Make sure that assert triggers even if we compile in release mode
#undef NDEBUG

#include <cassert> // for assert
#include <iostream>

bool isPrime(int x)
{
	bool isPrime { true };
	
	if (x <= 1)
	{
		isPrime = false;
		goto end;
	}
		
	for(int count{2};count<x;count++)
	{
		if ((x % count) == 0)
			isPrime = false;
	}
	
end:
    return isPrime;
    // write this function using a for loop
}

int main()
{
    assert(!isPrime(0)); // terminate program if isPrime(0) is true
    assert(!isPrime(1));
    assert(isPrime(2));  // terminate program if isPrime(2) is false
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

    return 0;
}
