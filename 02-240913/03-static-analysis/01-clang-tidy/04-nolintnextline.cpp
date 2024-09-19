#include <iostream>
#include <iostream>  // NOLINT(readability-duplicate-include)

int main() {
    const bool foo = true;
    const int x = 10;
    // NOLINTNEXTLINE(bugprone-branch-clone)
    if (2 * 2 == 4 && x == x && static_cast<long long>(x * x) == 100) {
        std::cout << "Hello\n";
    } else {
        std::cout << "Hello\n";
    }
}
