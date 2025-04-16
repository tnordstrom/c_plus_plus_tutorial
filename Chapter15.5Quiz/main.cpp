/* Tony Nordstrom */
/* April 16 02025 */
/* Chapter 15.5 quiz question 1 */

#include <iostream>
#include <string>

template <typename T, typename U, typename V>
class Triad
{
	private:
	
		T m_first{};
		U m_second{};
		V m_third{};
		
	public:
	
		Triad(const T& first, const U& second, const V& third)
			: m_first{ first }
			, m_second{ second }
			, m_third{ third }
		{
		}
	
		const T& first() const { return m_first; }
		const U& second() const { return m_second; }
		const V& third() const { return m_third; }
		
		void print() const;
};

template <typename T, typename U, typename V>
void Triad<T, U, V>::print() const
{
	std::cout << "[" << m_first << ", " << m_second << ", " << m_third << "]\n";
} 

int main()
{
 	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

	return 0;
}
