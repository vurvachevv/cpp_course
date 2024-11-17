#include <iostream>
#include "vector2f.hpp"

using std::cout, std::cin, std::endl;

int main()
{
    Vector2f v1, v2;

    cout << "Enter vector v1 (x y): ";
    cin >> v1;
    cout << "Enter vector v2 (x y): ";
    cin >> v2;

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    cout << "v1 + v2 = " << v1 + v2 << endl;
    cout << "v1 - v2 = " << v1 - v2 << endl;

    float scalar = 2.0f;
    cout << "v1 * " << scalar << " = " << v1 * scalar << endl;

    cout << "v1 * v2 (dot product) = " << v1 * v2 << endl;

    cout << "-v1 = " << -v1 << endl;
    cout << "+v1 = " << +v1 << endl;

    cout << "v1 == v2? " << (v1 == v2 ? "Yes" : "No") << endl;
    cout << "v1 != v2? " << (v1 != v2 ? "Yes" : "No") << endl;

    v1 += v2;
    cout << "v1 += v2; v1 = " << v1 << endl;

    v1 -= v2;
    cout << "v1 -= v2; v1 = " << v1 << endl;

    v1 *= scalar;
    cout << "v1 *= " << scalar << "; v1 = " << v1 << endl;

}
