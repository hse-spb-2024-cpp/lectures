#include <vector>

bool foo() {
    return true;
}

int main() {
    std::vector v{1, 2, 3};
    bool x = false;
    bool y = false;
    x = true;
    if (x && (y = false) && foo() > false) {  // cppcheck-suppress knownConditionTrueFalse
        if (x && (y = false) && foo() > false) {
            {
            }
        }
    }
}
