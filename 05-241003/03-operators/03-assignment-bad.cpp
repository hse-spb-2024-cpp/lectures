#include <cassert>
#include <iostream>
#include <vector>

struct bigint {
private:
    std::vector<int> digits;

public:
    bigint() {}
    bigint(int digit) : digits{digit} {
        assert(0 <= digit && digit < 10);
    }

    // DO NOT DO IT! It is auto-generated.
    void operator=(const bigint &other) {
        digits = other.digit;
        // It's also not totally correct implementation.
    }
};

int main() {
    bigint a = 4, b = 5;
    a = b;
}
