#pragma once
#include <iostream>

class Vector2f

{
private:
    float x, y;

public:
    Vector2f(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    Vector2f operator+(const Vector2f& other) const
    {
        return Vector2f(x + other.x, y + other.y);
    }

    Vector2f operator-(const Vector2f& other) const
    {
        return Vector2f(x - other.x, y - other.y);
    }

    Vector2f operator*(float scalar) const
    {
        return Vector2f(x * scalar, y * scalar);
    }

    float operator*(const Vector2f& other) const
    {
        return x * other.x + y * other.y;
    }

    Vector2f operator-() const
    {
        return Vector2f(-x, -y);
    }

    Vector2f operator+() const
    {
        return *this;
    }

    bool operator==(const Vector2f& other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2f& other) const
    {
        return !(*this == other);
    }

    Vector2f& operator+=(const Vector2f& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2f& operator-=(const Vector2f& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2f& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2f& v)
    {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector2f& v)
    {
        is >> v.x >> v.y;
        return is;
    }

};
