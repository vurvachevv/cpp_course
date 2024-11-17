#include <iostream>
#include "point.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using std::cout, std::endl;

class Circle
{
private:
    Point center;
    float radius;

public:
    Circle(const Point& center, float radius) : center(center), radius(radius > 0 ? radius : 0) {}
    Circle() : center(Point(0, 0)), radius(1.0f) {}
    Point getCenter() const { return center; }
    float getRadius() const { return radius; }
    float area() const { return M_PI * radius * radius; }
    float distance(const Point& p) const
    {
        float dist = center.distance(p) - radius;
        return dist > 0 ? dist : 0;
    }
    bool isColliding(const Circle& c) const
    {
        float dist = center.distance(c.center);
        return dist <= (radius + c.radius);
    }
    void move(const Point& p)
    {
        center.setX(center.getX() + p.getX());
        center.setY(center.getY() + p.getY());
    }
};

int main()
{
    Point p = {7, -1};
    Point q = {-4, 2};
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "p + q = " << p + q << endl;

    Circle a({4, 1}, 3);
    Circle b;

    cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl;
    cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

    cout << "Area of a = " << a.area() << endl;
    cout << "Distance from point p to circle a = " << a.distance(p) << endl;

    cout << "Collisions:" << endl;
    if (a.isColliding(b))
        cout << "Yes, a is colliding b" << endl;
    else
        cout << "No, a isn't colliding b" << endl;

    cout << "Moving b by {1, 1}:" << endl;
    b.move({1, 1});
    if (a.isColliding(b))
        cout << "Yes, a is colliding b" << endl;
    else
        cout << "No, a isn't colliding b" << endl;

    return 0;
}
