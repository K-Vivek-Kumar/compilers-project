#ifndef FUNCS_H
#define FUNCS_H

class Point
{
public:
    double x, y;

    Point();
    Point(double x, double y);

    Point operator+(const Point &other) const;
    void set(double x, double y);
};

#endif
