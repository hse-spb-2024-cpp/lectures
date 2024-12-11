#include <iostream>

struct Foo {
    operator bool() {
        return false;
    }
};

struct Bar {
    operator bool() {
        return true;
    }
};

struct Baz {
    operator int() {
        return 10;
    }
};

int main() {
    [[maybe_unused]] Foo f;
    [[maybe_unused]] Bar b;
    [[maybe_unused]] Baz z;
    [[maybe_unused]] bool x1 = f;  // implicit: user-defined
    [[maybe_unused]] bool x2 = b;  // implicit: user-defined
    [[maybe_unused]] bool x3 = z;  // implicit: user-defined + arithmetic
    [[maybe_unused]] int y1 = 10 + f;
    [[maybe_unused]] int y2 = 10 + b;
    [[maybe_unused]] int y3 = 10 + z;

    if (f) {}
    if (b) {}
    if (z) {}

    for (; f;) {}
    for (; b;) {}
    for (; z;) {}

    while (f) {}
    while (b) {}
    while (z) {}

    if (f == b) {}  // WTF
    if (f == z) {}  // WTF
    if (z == z) {}  // WTF
}
