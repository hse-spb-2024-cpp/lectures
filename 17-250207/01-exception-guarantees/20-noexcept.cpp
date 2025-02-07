#include <iostream>

void check_n(int n) {
    if (n < 0) {
        throw 0;
    }
}

void foo() noexcept {  // If exception: std::terminate(), no dtor calls
    std::cout << "foo() start\n";
    int n;
    std::cin >> n;
    check_n(n);
    std::cout << "foo() end\n";
}

// There was no difference with/without noexcept with this example, but it may happen:
// 1. Say hello to no-noexcept-move and strong exception safety (will be later).
// 2. One can optimize code like `i++; foo(); i++;` => `foo(); i += 2;`
// 3. There is no need to prepare for stack unwind.

int main() {
    try {
        foo();
    } catch (...) {
        std::cout << "Caught\n";
    }
}
