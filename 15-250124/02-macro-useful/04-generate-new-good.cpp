#include <iostream>

#define CONCAT2(a, b) a##b
#define CONCAT1(a, b) CONCAT2(a, b)
#define new_var int CONCAT1(var_, __COUNTER__)

int main() {
    new_var = 500;
    new_var = 600;
    new_var = 700;
    std::cout << var_0 << "\n";
    std::cout << var_1 << "\n";
    std::cout << var_2 << "\n";
}
