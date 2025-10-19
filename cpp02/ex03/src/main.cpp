#include <iostream>
#include "../inc/Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	std::cout << "    a: "<< a << "\n";
	std::cout << "    b: "<< b << "\n";
	std::cout << "    c: "<< c << "\n";
	std::cout << "point: "<< point << "\n";
	Fixed total_x(a.get_x() + b.get_x() + c.get_x());
	Fixed total_y(a.get_y() + b.get_y() + c.get_y());

	std::cout << "total_x: " << total_x << "\n";
	std::cout << "total_y: " << total_y << "\n";

	Fixed	vectorAB(b.get_x() - a.get_x());

	return (true);
}

int	main( void )
{
	bsp(Point(0, 0), Point(0, 3), Point(2, 1), Point(1, 1));
	return 0;
}