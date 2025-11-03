#include "Point.hpp"

bool	isVertex(Point point, Point vertex) {
	if (point.getX() == vertex.getX() && point.getY() == vertex.getY())
		return true;
	return false;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	float	aX = a.getX();
	float	aY = a.getY();
	float	bX = b.getX();
	float	bY = b.getY();
	float	cX = c.getX();
	float	cY = c.getY();
	float	pointX = point.getX();
	float	pointY = point.getY();
	float	areaABC = 0.5 * fabs((bX - aX) * (cY - aY) - (cX - aX) * (bY - aY));
	float	areaPBC = 0.5 * fabs((bX - pointX) * (cY - pointY) - (cX - pointX) * (bY - pointY));
	float	areaPCA = 0.5 * fabs((cX - aX) * (pointY - aY) - (pointX - aX) * (cY - aY));
	float	areaPAB = 0.5 * fabs((aX - bX) * (pointY - bY) - (pointX - bX) * (aY - bY));

	if ((areaPBC == 0.0) || (areaPCA == 0.0) || (areaPAB == 0.0)
		|| isVertex(point, a) == true || isVertex(point, b) == true || isVertex(point, c) == true)
		return false;
	if ((areaPBC + areaPCA + areaPAB == areaABC))
		return true;
	return false;
}
