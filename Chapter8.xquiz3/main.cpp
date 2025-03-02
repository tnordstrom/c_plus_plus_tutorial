/* Tony Nordstrom */
/* October 29 02024 */
/* Chapter 8.x quiz question 3 */

#include "random.h"
#include <iostream>

int main ( void )
{
	char answer { '0' };	
	int min { 0 };
	int max { 0 };
	int num_guesses { 0 };
	
	std::cout << "Minimum range: ";
	std::cin >> min;
	std::cout << "Maximum range: ";
	std::cin >> max;
	std::cout << "Number of guesses: ";
	std::cin >> num_guesses;
	 
	std::cout << "Let's play a game. I've picked a number between " << min << " and " << max << ". I'll give you " << num_guesses << " tries to guess it\n";
	
	do
	{
		int random_number { Random::get(min, max) };
		bool won { false };
		
		for (int i {1}; i <= num_guesses; i++)
		{
			std::cout << "Enter your guess #" << i << ": ";
			int guess { 0 };
			std::cin >> guess;
			
			if (guess > random_number)
			{
				std::cout << "Your guess is too high\n";
			}
			else if (guess < random_number)
			{
				std::cout << "Your guess is too low\n";
			}
			else
			{
				std::cout << "You guessed it!\n";
				won = true;
				break;
			}
		}
		
		if (won == false)
		{
			std::cout << "Too bad. You lose. The correct number was " << random_number << '\n';
		}
		
		std::cout << "Would you like to play again? y/n: ";

		std::cin >> answer;
		
	} while (answer == 'y');
	
	std::cout << "Thanks for playing\n";
	
	return 0;
}
