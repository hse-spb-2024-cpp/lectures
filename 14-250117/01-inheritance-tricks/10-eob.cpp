#include <iostream>
// Empty Base Optimization (EOB)

struct Foo {};
struct Bar {};

struct Baz1 {
    Foo f;
    Bar b;
    int x;
};

struct Baz2 : Foo {  // empty base
    int x;
};

int main() {
    Baz1 bz1;
    std::cout << sizeof(Foo) << " " << sizeof(Bar) << " " << sizeof(Baz1) << "\n";
    std::cout << &bz1.f << "\n";
    std::cout << &bz1.b << "\n";
    std::cout << &bz1.x << "\n";

    Baz2 bz2;
    std::cout << sizeof(bz2) << "\n";
    std::cout << &bz2.x << "\n";
}
