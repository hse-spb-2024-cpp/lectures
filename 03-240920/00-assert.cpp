#include <cassert>
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int m = (a + b) / 2;
    assert(a <= m && m <= b);
}
