#include <cassert>
#include <iostream>

bool read_int(int *i_out) {
    std::cin >> *i_out;
    return static_cast<bool>(std::cin);
}

int main() {
    [[maybe_unused]] bool result;

    int i = 0;
    result = read_int(&i);
    assert(result);
    std::cout << i << "\n";
}
