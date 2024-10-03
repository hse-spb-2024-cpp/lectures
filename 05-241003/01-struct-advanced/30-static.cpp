#include <iostream>

struct Foo {
private:
    // `const` is also fine, but needs some trickery.
    static constexpr int SECRET = 10;

    // No `inline` is also fine, but needs some trickery.
    static inline int COUNTER = 0;

public:
    // Does not have `this`.  Like a free function, but sees `private`.
    static int foo() {
        increment_counter();  // No need in a function, actually.
        return SECRET + COUNTER;
    }

private:
    // Affected by `private`/`public`.
    static void increment_counter() {
        ++COUNTER;
    }
};

int main() {
    std::cout << Foo::foo() << "\n";
    std::cout << Foo::foo() << "\n";
    // std::cout << Foo::SECRET << "\n";
    // std::cout << Foo::COUNTER << "\n";
    // Foo::increment_counter();
}
