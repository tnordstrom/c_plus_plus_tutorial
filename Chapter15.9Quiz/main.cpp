/* Tony Nordstrom */
/* May 9 02025 */
/* Chapter 15.9 quiz question 3 */
/* Build by  g++ -Wall -o "main" "main.cpp" "Point3d.cpp" "Vector3d.cpp" */

#include "Vector3d.h"
#include "Point3d.h"

int main()
{
	Point3d p { 1.0, 2.0, 3.0 };
	Vector3d v { 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}
