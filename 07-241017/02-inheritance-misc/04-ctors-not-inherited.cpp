#include <cassert>
#include <iostream>

struct Base {
    int x;
    Base(int x_) : x(x_) {}

    void print_x() {
        std::cout << x << "\n";
    }
};

struct DerivedNaive : Base {
    // DerivedNaive(int x_) : Base(x_) {}
};

int main() {
    DerivedNaive dn(10);  // Конструкторы не наследуются.
    dn.print_x();  // ok
}
