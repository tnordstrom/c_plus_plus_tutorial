/* Tony Nordstrom */
/* October 21 02024 */
/* Chapter 8.8 quiz question 4 */

#include <iostream>

int main()
{
    // outer loops between 1 and 5
    int outer{ 1 };
    while (outer <= 5)
    {
        // For each iteration of the outer loop, the code in the body of the loop executes once

        // inner loops between 1 and outer
        // note: inner will be created and destroyed at the end of the block
        int inner{ 5 };
        while (inner >= 1)
        {
            if (inner <= outer)
				std::cout << inner << ' ';
			else
				std::cout << "  ";
				
            --inner;
        }

        // print a newline at the end of each row
        std::cout << '\n';
        ++outer;
    } // inner destroyed here

    return 0;
}
