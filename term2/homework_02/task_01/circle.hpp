#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "point.hpp"
#include <cmath>

class Circle
{
private:
    Point center;
    float radius;

public:
    Circle(const Point& center, float radius);
    Circle();
    Circle(const Circle& circle);
    Point getCenter() const;
    float getRadius() const;
    void setCenter(const Point& center);
    void setRadius(float radius);
    float area() const;
    float distance(const Point& p) const;
    bool isColliding(const Circle& c) const;
    void move(const Point& p);
};

#endif
