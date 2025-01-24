/* Tony Nordstrom */
/* January 15 02025 */
/* Chapter 13.10 quiz question 2 */
/* question 3: because the value must hang around outside scope of getFraction? */

#include <iostream>

struct Fraction
{
	int numerator { 0 };
	int denominator { 1 };
};
	
Fraction getFraction(void)
{
	Fraction temp;
	
	std::cout << "Enter a value for the numerator: ";
	std::cin >> temp.numerator;
	std::cout << "Enter a value for the denominator: ";
	std::cin >> temp.denominator;
	
	return (temp);
}

constexpr Fraction multFraction(const Fraction& a, const Fraction& b)
{
	Fraction result;
	
	result.numerator = a.numerator * b.numerator;
	result.denominator = a.denominator * b.denominator;
	
	return (result);
}

void printFraction(const Fraction& f)
{
	std::cout << f.numerator << "/" << f.denominator;
	
	return;
}

int main ( void )
{
	Fraction a;
	Fraction b;
	Fraction c;
	
	a = getFraction();
	b = getFraction();
	c = multFraction(a, b);
	std::cout << "Your fractions multiplied together: ";
	printFraction(c);
	std::cout << '\n';
	
	return 0;
}
