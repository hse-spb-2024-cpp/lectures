#include <vector>

// cppcheck -DSOME_DEFINE_TO_FIX_CONFIG --enable=all --suppressions-list=cppcheck-suppressions.txt --error-exitcode=1 --inline-suppr 01-warnings.cpp
bool foo() {
    return true;
}

int main() {
    std::vector v{1, 2, 3};
    bool x = false;
    bool y = false;
    x = true;
    if (x && (y = false) && foo() > false) {
    }
}
