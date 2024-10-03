#include <iostream>

struct Foo {
private:
    int field = 10;

public:
    void increment() {
        field++;
    }
    
private:  // private, public, does not matter, visible to all
    // Sees all private.
    friend bool eq(const Foo &a, const Foo &b) {
        // no `this`.
        return a.field == b.field;
    }
    friend bool operator==(const Foo &a, const Foo &b) {
        return a.field == b.field;
    }
};

bool operator!=(const Foo &a, const Foo &b) {
    return !(a == b);
}

int main() {
    Foo f1, f2;
    // f1.field = 5;

    std::cout << (f1.field == f2.field) << "\n";

    f1.increment();
    std::cout << eq(f1, f2) << "\n";  // 0
    f2.increment();
    std::cout << eq(f1, f2) << "\n";  // 1

    std::cout << (f1 == f2) << "\n";
    // std::cout << f1 Foo::== f2 << "\n";
    // std::cout << Foo::operator==(f1, f2) << "\n";
}
