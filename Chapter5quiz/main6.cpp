/* Tony Nordstrom */
/* September 21 02024 */
/* Chapter 5 quiz question 6 */

#include <iostream>
#include <string_view>

// Write the function getQuantityPhrase() here
std::string getQuantityPhrase(int quantity)
{
	std::string result { };
	
	/*
	 *     < 0 = “negative”
    0 = “no”
    1 = “a single”
    2 = “a couple of”
    3 = “a few”
    > 3 = “many”
	 * */
	if (quantity < 0)
		result = "negative";
	else if (quantity == 0)
		result = "no";
	else if (quantity == 1)
		result = "a single";
	else if (quantity == 2)
		result = "a couple of";
	else if (quantity == 3)
		result = "a few";
	else if (quantity > 3)
		result = "many";
		
	return result;	
}

// Write the function getApplesPluralized() here
constexpr std::string_view getApplesPluralized(int num)
{
	return ((num == 1) ? "apple" : "apples");
}

int main()
{
    constexpr int maryApples { 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}
