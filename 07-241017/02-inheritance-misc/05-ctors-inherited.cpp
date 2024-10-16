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
    using Base::Base;  // показать конструкторы из базового класса
};

int main() {
    DerivedNaive dn(10);
    dn.print_x();  // ok
}
