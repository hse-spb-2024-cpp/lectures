#include <cassert>

struct Base {
    int x;
    Base(int x_) : x(x_) {}
};

struct Derived : Base {
    int y = 20;

    Derived() : Base(10) {}
    // Derived(int y_) : y(y_), Base(y) {}  // -Wreorder, UB: read from uninitialized field
    // Derived(int y_) : Base(y), y(y_) {}  // UB is apparent
};

int main() {
    Derived d;
    assert(d.x == 10);
}
