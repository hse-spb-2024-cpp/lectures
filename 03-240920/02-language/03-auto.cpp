#include <iostream>

int main() {
    // Since C++11
    auto x = 1'000'000'000;   // int
    auto y = 1'000'000'000LL; // long long
    auto x2 = 2 * x;          // int * int, int
    auto y2 = 2 * y;          // int * long long, long long
    std::cout << x2 << " " << y2 << " " << sizeof(x2) << "\n";

    // auto x3 = 2 * x, y3 = 2 * y;  // CE: inconsistent deduction for 'auto'

    // `auto` works with other types as well, but it is always deduced from the
    // initialization.

    auto z = 1;  // int
    z = z * 1.5;  // `z * 1.5` - double

    // Does not work:
    auto tmp; tmp = 12;
}
