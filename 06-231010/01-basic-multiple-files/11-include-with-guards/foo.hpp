#ifndef FOO_HPP_  // Include guards
#define FOO_HPP_

#include <vector>
#include <iostream>

struct Foo {
    int a = 10;
    std::vector<int> v;

    void method1();

    void method2() {
        std::cout << "method_unused() called " << a << "\n";
    }
};

Foo get_foo();

#endif  // FOO_HPP_
