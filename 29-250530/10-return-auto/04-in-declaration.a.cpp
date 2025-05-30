#include <iostream>

auto foo();
auto bar();

auto baz() {
    // return foo();  // compilation error: return type of `foo` is not yet known
}

auto foo() {
    return 10;
}

int main() {
    std::cout << foo() << "\n";
    // std::cout << bar() << "\n";  // compilation error: `auto` is not deduced, it's in another TU.
}
