#include <iostream>

namespace mipt
{
    namespace fefm
    {
        struct Point
        {
            int x, y;
        };
    }

    namespace frtk
    {
        void print(fefm::Point p)
        {
            std::cout << p.x << " " << p.y << std::endl;
        }
    }
}

using namespace mipt::fefm;
using namespace mipt::frtk;

int main()
{
    Point p;
    p.x = 10;
    p.y = 20;

    print(p);
}
