// #pragma once  // Non-standard alternative
#ifndef FOO_HPP_  // Obligatory
#define FOO_HPP_

#include <vector>

struct Foo {
    int a = 10;
    std::vector<int> v;

    void method();
    void method_unused();
};

Foo get_foo();

#endif  // FOO_HPP_
