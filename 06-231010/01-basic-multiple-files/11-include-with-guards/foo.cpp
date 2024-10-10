#include <vector>
#include <iostream>
#include "foo.hpp"

Foo get_foo() {
    return Foo{};
}

void Foo::method1() {
    std::cout << "method2() called " << a << "\n";
}
