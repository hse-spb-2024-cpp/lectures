#include <vector>

bool foo() {
    return true;
}

int main() {
    std::vector v{1, 2, 3};
    bool x = false;
    bool y = false;
    x = true;
    // cppcheck-suppress
    if (x && (y = false) && foo() > false) {  // cppcheck-suppress
    }
}
