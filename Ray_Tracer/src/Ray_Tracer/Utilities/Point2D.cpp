#include "Point2D.h"



Point2D::Point2D()
	:x(0), y(0)
{
}

Point2D::Point2D(const double a)
	:x(a), y(a)
{
}

Point2D::Point2D(const double a, const double b)
	:x(a), y(b)
{
}

Point2D::Point2D(const Point2D & p)
	:x(p.x), y(p.y)
{
}


Point2D::~Point2D()
{
}
