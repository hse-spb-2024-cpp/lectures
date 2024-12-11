#include <cmath>
#include <iostream>

int main() {
    // floating-point numbers, IEEE-754
    double x = 1.2;  // mantissa * 2^{exponent}
    x += 2.3;

    std::cout << 1.2 << "\n";
    std::cout << 2.3 << "\n";
    std::cout.precision(100);
    std::cout << 1.2 << "\n";
    std::cout << 2.3 << "\n";
    std::cout << x << "\n";

    std::cout << "=====\n";
    // https://0.30000000000000004.com/
    std::cout << 0.1 + 0.2 << "\n";
    std::cout << 0.3 << "\n";
    std::cout << (0.1 + 0.2 == 0.3) << "\n";  // 0
    std::cout << (0.1 + 0.2 - 0.3) << "\n";
    std::cout << "=====\n";

    auto y = 1.2e100;  // double
    std::cout << y << "\n";
    std::cout << static_cast<float>(y) << "\n";

    double z = 1.23456789;
    std::cout << z << "\n";
    std::cout << static_cast<float>(z) << "\n";

    long double lz1 = 1.23456789;  // double literal
    std::cout << lz1 << "\n";
    std::cout << static_cast<long double>(z) << "\n";

    long double lz2 = 1.23456789L;  // long double literal
    std::cout << lz2 << "\n";
}
