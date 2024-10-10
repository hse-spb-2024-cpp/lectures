#include <vector>
#include <iostream>
#include "foo.hpp"

int main() {
    get_foo().method1();

    Foo f = get_foo();
    f.method2();

    Foo f2;
    f2.method2();
}
