#include <iostream>

// https://en.cppreference.com/w/cpp/language/integer_literal

int main() {
    int a;

    std::cout << 12'345 << "\n";  // C++14

    a = 123;                                                    // decimal
    std::cout << a << " " << 100 * 1 + 10 * 2 + 1 * 3 << "\n";  // 123

    a = 0x2F;  // hexadecimal: 0x or 0X
    a = 0x2f;
    std::cout << a << " " << 2 * 16 + 1 * 15 << "\n";  // 47
    a = 47;  // same

    a = 0xDEADBEEF;

    a = 0123;                                                 // octal
    std::cout << a << " " << 64 * 1 + 8 * 2 + 1 * 3 << "\n";  // 83

    a = 0b1101;                                  // binary (C++14)
    std::cout << a << " " << 8 + 4 + 1 << "\n";  // 13

    // `std::cin` and `std::stoi` - always decimal, unless configured otherwise

    [[maybe_unused]] auto a_int = 10;  // int
    [[maybe_unused]] auto a_unsigned = 10U;  // unsigned int
    [[maybe_unused]] auto a_long = 10L;  // long
    [[maybe_unused]] auto a_longlong = 10LL;  // long long
    [[maybe_unused]] auto a_unsignedlonglong = 10ULL;  // unsigned long long
}
