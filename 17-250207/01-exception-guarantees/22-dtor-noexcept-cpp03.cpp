#include <iostream>

void maybe_throw() {
    static int remaining = 2;
    if (!--remaining) {
        throw 0;
    }
}

struct Foo {
    Foo() {
        std::cout << "Foo() " << this << "\n";
    }
    ~Foo() {
        std::cout << "~Foo() " << this << "\n";
        maybe_throw();
    }
};

#if __cplusplus > 200301L
#error This file requires C++03
#endif

int main() {
    try {
        try {
            Foo a;
            Foo b;
            Foo c;
            std::cout << "before throw\n";
            // throw 1;  // TODO: try uncommenting
            std::cout << "after throw\n";
        } catch (int x) {
            std::cout << "caught " << x << "\n";
        } catch (...) {
            std::cout << "caught something\n";
        }
    } catch (...) {
        std::cout << "caught outside\n";
    }
    // C++03: two exceptions simultanously => std::terminate().
    // C++11: dtors are noexcept, always std::terminate().
}
