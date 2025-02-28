#include <iostream>

struct Bar {
    int i = 0;
    char c = 0;
    char c2 = 0;
    // padding
};

struct BarDerived : Bar {
    char c3 = 0;  // can be put into padding in `Bar`
    int i2 = 0;
};

int main() {
    std::cout << sizeof(Bar) << "\n";
    std::cout << sizeof(BarDerived) << "\n";
}
