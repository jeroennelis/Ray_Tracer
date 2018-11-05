#pragma once
class Point2D
{
public:
	double x, y;

	Point2D();													// default constructor
	Point2D(const double a);									// constructor
	Point2D(const double a, const double b);	// constructor
	Point2D(const Point2D& p);									// copy constructor
	~Point2D();													// destructor
};

