/* September 26 02024 */
/* Tony Nordstrom */
/* Chapter O.3 Question 1a-d */

#include <bitset>
#include <cstdint>
#include <iostream>

int main()
{
    [[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
    [[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
    [[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
    [[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
    [[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };

    std::uint8_t myArticleFlags{ option_favorited };

    // Place all lines of code for the following quiz here
	// Question 1a)
	myArticleFlags |= option_viewed;
	// Question 1b)
	if (myArticleFlags & option_deleted)
	{
		std::cout << "Deleted\n";
	}
	// Question 1c)
	myArticleFlags &= static_cast<std::uint8_t>(~option_favorited);
	// Why is the static cast needed? It's already that type??
	// And why is 1a) not using a static cast?
	// Is it because the ~ implicitly casts to another type?
	// Ah yes, see O.3 Key Insight

	// Question 1d)
	// De Morgan's theorem says the following are equivalent:
	// myflags &= ~(option4 | option5);
	// myflags &= ~option4 & ~option5; 
	
	
    std::cout << std::bitset<8>{ myArticleFlags } << '\n';

    return 0;
}
