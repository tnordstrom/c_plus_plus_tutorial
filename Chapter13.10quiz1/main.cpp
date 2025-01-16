/* Tony Nordstrom */
/* January 15 02025 */
/* Chapter 13.10 quiz question 1 */

#include <iostream>

struct Revenue
{
	int ads_watched { 0 };
	int percent_click { 0 };
	double earnings_per_ad { 0.0 };
};
	
void printData(const Revenue &data)
{
	std::cout << "Ads watched: " << data.ads_watched << " Percent clicked: " << data.percent_click << " Earnings per ad: " << data.earnings_per_ad << '\n';
	std::cout << "Total revenue: " << data.ads_watched * data.percent_click / 100 * data.earnings_per_ad << '\n';
	
	return;
}

int main ( void )
{
	Revenue data { };
	
	std::cout << "Ads watched: ";
	std::cin >> data.ads_watched;
	std::cout << "Percent clicked: ";
	std::cin >> data.percent_click;
	std::cout << "Earnings per ad: ";
	std::cin >> data.earnings_per_ad;
	
	printData(data);
	
	return 0;
}
