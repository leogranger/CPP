#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    // Inside triangle
    Point p1(2.0f, 2.0f);

    // Outside triangle
    Point p2(10.0f, 10.0f);

    // On edge
    Point p3(5.0f, 0.0f);

    // On vertex
    Point p4(0.0f, 0.0f);

    // too close inside
    Point p5(0.001f, 0.001f);

    // too close outside
    Point p6(-0.001f, 0.001f);

    std::cout << "p1 inside? " << bsp(a, b, c, p1) << std::endl;
    std::cout << "p2 inside? " << bsp(a, b, c, p2) << std::endl;
    std::cout << "p3 inside? " << bsp(a, b, c, p3) << std::endl;
    std::cout << "p4 inside? " << bsp(a, b, c, p4) << std::endl;
    std::cout << "reverse order? " << bsp(c, b, a, p2) << std::endl;
    std::cout << "p5 inside ? " << bsp(a, b, c, p5) << std::endl;
    std::cout << "p6 inside ? " << bsp(a, b, c, p6) << std::endl;

    return 0;
}
