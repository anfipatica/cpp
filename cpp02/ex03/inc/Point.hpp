#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &point);
		Point &operator=(const Point &point);
		~Point(void);
		Fixed get_x(void) const;
		Fixed get_y(void) const;

	private:
		const Fixed	_x;
		const Fixed	_y;
};

std::ostream &operator<<(std::ostream &os, const Point &p);

#endif