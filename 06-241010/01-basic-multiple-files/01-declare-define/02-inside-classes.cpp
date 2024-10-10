#include <iostream>

struct Foo {
    // void bar();  // Prohibited.

    void foo() {
        bar();
    }

    void bar() {
        foo();
    }
};

int main() {
}
