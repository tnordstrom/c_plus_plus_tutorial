/* Tony Nordstrom - September 16 02024 */
#include <iostream>

int enterNumber(void)
{
	int num{ };
	std::cout << "Enter a number 10 or lower: ";
	std::cin >> num;
	if (num > 10)
	{
		std::cout << "Out of range\n";
	}
	return(num);
}

/* Determines if a number <= 10 is prime, greater numbers always return false */
bool isPrime(int val)
{
	bool result{ false };
	
	switch(val)
	{
		case 0:
		case 1:
		case 4:
		case 6:
		case 8:
		case 9:
		case 10:
			break;
		case 2:
		case 3:
		case 5:
		case 7:
			result = true;
			break;
		default:
			break;
	}
	return result;
}

int main()
{
	char ch{ 'a' };
	std::cout << ch << " is equivalent to " << static_cast<int>(ch) << '\n';
	
	int val{ enterNumber() };
	
	std::cout << val << " is " << (isPrime(val) ? "prime" : "not prime") << '\n';
	
	
	return 0;
}
