#include "Fixed.hpp"

int main()
{
    Fixed a(5);
    Fixed b(10);
    Fixed c(5);

    std::cout << "\n===== COMPARISON =====\n";

    std::cout << (a > b) << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << (a >= c) << std::endl;
    std::cout << (a <= c) << std::endl;
    std::cout << (a == c) << std::endl;
    std::cout << (a != c) << std::endl;

    std::cout << "\n===== INT ARITHMETIC OPERATIONS =====\n";

	std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;

    std::cout << "\n===== FLOAT ARITHMETIC OPERATIONS =====\n";

    Fixed e(0.5f);
    Fixed d(0.25f);

    std::cout << e + d << std::endl;
    std::cout << e - d << std::endl;
    std::cout << e * d << std::endl;
    std::cout << e / d << std::endl;

    std::cout << "\n===== INCREMENTATIONS =====\n";

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << "\n===== MIN/MAX =====\n";

    std::cout << Fixed::min(a,b) << std::endl;
    std::cout << Fixed::max(a,b) << std::endl;

    const Fixed f(1.5f);
    const Fixed g(2.5f);

    std::cout << Fixed::min(f,g) << std::endl;
    std::cout << Fixed::max(f,g) << std::endl;
}