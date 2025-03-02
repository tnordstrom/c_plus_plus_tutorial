/* Tony Nordstrom */
/* February 26 02025 */
/* Chapter 14.10 quiz */

#include <iostream>
#include <string>
#include <string_view>

class Ball
{
	private:
	
		std::string m_color { };
		double m_radius { };
		
	public:

		Ball(std::string_view color, double radius)
		: m_color { color }
		, m_radius { radius }
		{
		}
		
		const std::string& g_color() const
		{
			return m_color;
		}
		
		double g_radius() const
		{
			return m_radius;
		}
};

void print(const Ball& ball)
{
	std::cout << "Ball(" << ball.g_color() << ", " << ball.g_radius() << ")\n";
}

int main()
{
	Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);

	return 0;
}
