#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& source);
		Point&	operator=(const Point& source);
		~Point();

		float	getX(void) const;
		float	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
