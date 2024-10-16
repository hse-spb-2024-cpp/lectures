#include <cassert>

struct Base {
    int x;
    Base(int x_) : x(x_) {}
};

struct Derived : Base {
    int y = 20;

    // Derived() { Base(10); }  // wrong
    Derived() : Base(10) {}
    Derived(int y_) : Base(y_), y(y_) {}  // OK
};

struct SubDerived : Derived {
    SubDerived([[maybe_unused]] int unused) {}  // : Derived() is implied.
};

int main() {
    Derived d;
    assert(d.x == 10);

    SubDerived sd(23456);
    assert(sd.y == 20);
    assert(sd.x == 10);
}
