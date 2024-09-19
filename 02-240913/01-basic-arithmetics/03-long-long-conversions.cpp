#include <iostream>

int main() {
    int a = 1'000'000'000;
    std::cout << sizeof(a) << " " << sizeof(long long) << "\n";
    {
        long long b =
            a * a;  // UB: int * int is calculated inside int (signed overflow,
                    // UB), and is then converted to long long
        // Check with -fsanitize=undefined
        std::cout << b << "\n";

        long long c = 1'000'000'000 * 1'000'000'000;
        std::cout << c << "\n";
    }
    {
        long long all = a;   // implicit conversion from int to 'long long'
        long long b = all * all;  // long long * long long
        std::cout << b << "\n";
    }
    {
        // Explicit conversion to `long long`.
        long long b = static_cast<long long>(a) * a;  // long long * int
        // See "Usual arithmetic conversions" in
        // https://en.cppreference.com/w/c/language/conversion
        std::cout << b << "\n";
    }
    {
        // Olympic style.
        long long b = 1LL * a * a;  // long long literal * int * int
        std::cout << b << "\n";
    }
    {
        // C-style cast, do not use.
        long long b = (long long)a * a;  // long long * int
        std::cout << b << "\n";
    }
}
