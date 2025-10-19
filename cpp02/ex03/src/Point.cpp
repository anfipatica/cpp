#include "../inc/Point.hpp"

Point::Point(void): _x(0), _y(0)
{
	std::cout << "a" << std::endl;
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
	std::cout << "b" << std::endl;

}

Point::Point(const Point &point): _x(point._x), _y(point._y)
{
	std::cout << "c" << std::endl;
}

Fixed Point::get_x(void) const
{
	return (this->_x);
}

Fixed Point::get_y(void) const
{
	return (this->_y);
}

/* Since the only variables the class has are const, it makes no sense to
implement its modification. Once the constructor assigns their value, they should
not be changed.*/
Point &Point::operator=(const Point &point)
{
	std::cout << "d" << std::endl;
	(void)point;
	return (*this);
}

Point::~Point(void)
{}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
	os << "[x: " << p.get_x() << "|y: " << p.get_y() << "]";
	return (os);
}


