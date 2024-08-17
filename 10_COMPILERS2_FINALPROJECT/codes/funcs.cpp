#include "funcs.h"
#include <iostream>

Point::Point() : x(0.0), y(0.0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point Point::operator+(const Point &other) const
{
    return Point(x + other.x, y + other.y);
}

void Point::set(double x, double y)
{
    this->x = x;
    this->y = y;
}