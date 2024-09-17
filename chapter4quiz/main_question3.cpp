/* Tony Nordstrom - Sept 16 02024 */
/* Chapter 4 quiz - Question 3 */

#include <iostream>

double getHeight(void)
{
	std::cout << "Enter tower height in meters: ";
	double x { };
	std::cin >> x;
	
	return x;
}

int main()
{
	double tower_height { getHeight() };
	double g { 9.8 };
	double distance_fallen { 0.0 };
	int seconds { 0 };
	
	for (seconds = 0; seconds < 6; seconds++)
	{
		distance_fallen = g * seconds * seconds / 2; /* Is implicit cast ok here? */
		if (distance_fallen > tower_height)
			std::cout << "At " << seconds << " seconds, the ball is on the ground\n";
		else
			std::cout << "At " << seconds << " seconds, the ball is at height: " << tower_height - distance_fallen << " meters\n";
	}
	
	return 0;
}
