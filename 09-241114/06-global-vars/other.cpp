#include <iostream>
#include "other.hpp"

int global_var = 10;  // initialized in exactly one translation unit

void do_other() {
    std::cout << "do_other()\n";
    std::cout << &global_var << " " << global_var << "\n";
    std::cout << &TEN << " " << TEN << "\n";
    std::cout << &HELLO << " " << HELLO << "\n";
}
