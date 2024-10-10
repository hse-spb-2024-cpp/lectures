#include <vector>
#include <iostream>

// Should have definition.  Exactly the same in
// all files, otherwise worse than UB.
struct Foo {
    int a = 10;
    std::vector<int> v;

    void method1();

    void method2() {
        std::cout << "method_unused() called " << a << "\n";
    }
};

Foo get_foo();

int main() {
    get_foo().method1();

    Foo f = get_foo();
    f.method2();

    Foo f2;
    f2.method2();
}
