#include <iostream>

class Integer
{
public:
    int value;
};

class Real
{
public:
    float value;
};

class Boolean
{
public:
    bool value;
};

class Point
{
public:
    float x, y;
};

class LineSeg
{
public:
    float x1, y1, x2, y2;
};

Point operator+(const Integer &a, const Point &b)
{
    Point result;
    result.x = a.value + b.x;
    result.y = a.value + b.y;
    return result;
}