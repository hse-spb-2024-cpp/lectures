#include <cassert>
#include <iostream>

int main() {
    alignas(0x100) char data[sizeof(long long) + 1]{};
    long long *x = (long long*)(data + 1);
    std::cout << x << "\n";
    *x = 10;
    std::cout << *x << "\n";
}
