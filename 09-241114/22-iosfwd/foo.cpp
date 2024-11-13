#include "foo.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream &os, const Foo&) {
    return os << "hello world";
}
