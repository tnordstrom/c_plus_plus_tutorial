/* Tony Nordstrom */
/* March 17 02025 */
/* Chapter 14.x quiz Question 2 */

#include <iostream>

class Fraction
{
	private:
	
		int m_numerator{ 0 };
		int m_denominator{ 1 };

	public:
	
		explicit Fraction(int n = 0, int d = 1)
		: m_numerator { n }
		, m_denominator { d }
		{
		}
		

	void getFraction()
	{
		std::cout << "Enter a value for numerator: ";
		std::cin >> m_numerator;
		std::cout << "Enter a value for denominator: ";
		std::cin >> m_denominator;
		std::cout << '\n';
	}

	Fraction multiply(const Fraction& f) const	
	{
		return Fraction{ m_numerator * f.m_numerator, m_denominator * f.m_denominator };
	}

	void printFraction() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
		
};

int main()
{
    Fraction f1{ };
	f1.getFraction();
	
    Fraction f2{ };
	f2.getFraction();
	
    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).printFraction();

    return 0;
}
