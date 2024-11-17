#include "circle.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circle::Circle(const Point& center, float radius) : center(center), radius(radius > 0 ? radius : 0) {}

Circle::Circle() : center(Point(0, 0)), radius(1.0f) {}

Circle::Circle(const Circle& circle) : center(circle.center), radius(circle.radius) {}

Point Circle::getCenter() const
{
    return center;
}

float Circle::getRadius() const
{
    return radius;
}

void Circle::setCenter(const Point& center)
{
    this->center = center;
}

void Circle::setRadius(float radius)
{
    this->radius = radius > 0 ? radius : 0;
}

float Circle::area() const
{
    return M_PI * radius * radius;
}

float Circle::distance(const Point& p) const
{
    float dist = center.distance(p) - radius;
    return dist > 0 ? dist : 0;
}

bool Circle::isColliding(const Circle& c) const
{
    float dist = center.distance(c.center);
    return dist <= (radius + c.radius);
}

void Circle::move(const Point& p)
{
    center.setX(center.getX() + p.getX());
    center.setY(center.getY() + p.getY());
}
