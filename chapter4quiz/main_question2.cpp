/* Tony Nordstrom - Sept 16 02024 */
/* Chapter 4 quiz - Question 2 */

#include <iostream>

double getValue(void)
{
	std::cout << "Enter a double: ";
	
	double val{ };
	std::cin >> val;
	
	return val;
}

char getOperator(void)
{
	std::cout << "Enter an operator (+,-,/,*): ";
	
	char x { };
	std::cin >> x;
	
	return x;
}

int main()
{
	double x { getValue() };
	double y { getValue() };
	double result { };
	bool printresult { true };
	
	char op { getOperator() };
	
	std::cout << x << " and " << y << " were entered\n";
	std::cout << op << " was entered for the operator\n";
	
	if (op == '+')
		result = x + y;
	else if (op == '-')
		result = x - y;
	else if (op == '/')
		result = x / y;
	else if (op == '*')
		result = x * y;
	else
		printresult = false;
		
	if (printresult == true)
		std::cout << x << " " << op << " " << y << " is " << result << '\n';
	
	
	return 0;
}
