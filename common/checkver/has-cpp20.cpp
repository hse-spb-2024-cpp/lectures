#include <iostream>
#include <vector>

consteval int f() {  // Requires C++20.
    return 0;
}

int main() {
    std::cout << "Hello World!\n";
    std::vector vec{1, 2, 3, 4};  // Requires C++17.
    std::cout << "1 == " << vec[0] << "\n";
}
