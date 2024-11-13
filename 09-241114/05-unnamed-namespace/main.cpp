#include <iostream>
#include "other.hpp"

// external linkage
void foo() {
    std::cout << "main foo\n";
}

int main() {
    foo();
    do_other();
}
