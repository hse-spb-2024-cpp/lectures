#include <iostream>

int& foo() {
    int x = 123;
    return x;
}

int main() {
    int &x = foo();
    std::cout << x << "\n";  // UB
}
