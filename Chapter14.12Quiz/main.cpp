/* Tony Nordstrom */
/* March 6 02025 */
/* Chapter 14.12 quiz */

#include <iostream>
#include <string>
#include <string_view>

class Ball
{
	private:
		std::string m_color { "black" };
		double m_radius { 10.0 };

	public:
#if 0 // Individual constructors for each case
		Ball()
		{
			print();
		}
		Ball( std::string_view color ) : m_color { color }
		{
			print();
		}
		Ball( double radius ) : m_radius { radius }
		{
			print();
		}
		Ball( std::string_view color, double radius ) : m_color { color }, m_radius { radius }
		{
			print();
		}
#else // reduced constructor set by using default arguments and delegation
		Ball(double radius) : Ball{ "black", radius }
		{
		}
		Ball(std::string_view color="black", double radius=10.0)
			: m_color { color }
			, m_radius { radius }
		{
			print();
		}
#endif
		
		void print() const
		{
			std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
		}
		
};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}
