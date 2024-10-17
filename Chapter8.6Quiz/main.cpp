/* October 17 02024 */
/* Tony Nordstrom */
/* Chapter 8.6 Quiz */

#include <iostream>

int calculate (int x, int y, char op)
{
	int result {0};
	
	switch (op)
	{
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		result = x / y;
		break;
	case '%':
		result = x % y;
		break;
	default:
		std::cout << "Invalid operator: " << op << '\n';
		break;
	}
	
	return result;
}

int main (void)
{
	std::cout << "Enter one integer: ";
	int x { 0 };
	std::cin >> x;
	
	std::cout << "Enter another integer: ";
	int y { 0 };
	std::cin >> y;
	
	std::cout << "Enter an operator: (+,-,*,/,%) ";
	char op { '0' };
	std::cin >> op;
	
	std::cout << x << ' ' << op << ' ' << y << " equals " << calculate(x, y, op) << '\n';
	
	return 0;
}
