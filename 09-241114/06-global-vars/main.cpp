#include <iostream>
#include "other.hpp"

int main() {
    std::cout << "main()\n";
    std::cout << &global_var << " " << global_var << "\n";
    std::cout << &TEN << " " << TEN << "\n";
    std::cout << &HELLO << " " << HELLO << "\n";
    do_other();
}
