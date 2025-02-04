/* Tony Nordstrom */
/* February 3 02025 */
/* Chapter 14.5 quiz question 2 */

#include <iostream>

class Point3d
{
	private:
	
		int m_x { 0 };
		int m_y { 0 };
		int m_z { 0 };
		
	public:
	
		void print (void) const
		{
			std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">\n";
			
			return;
		}
		
		void setValues(int x, int y, int z)
		{
			m_x = x;
			m_y = y;
			m_z = z;
			
			return;
		}
		
		bool isEqual(Point3d point)
		{
			return (m_x == point.m_x) && (m_y == point.m_y) && (m_z == point.m_z);
		}
};

int main ( void )
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
	Point3d point1{};
	point1.setValues(1, 2, 3);

	Point3d point2{};
	point2.setValues(1, 2, 3);

	std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

	Point3d point3{};
	point3.setValues(3, 4, 5);

	std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

    return 0;
}
