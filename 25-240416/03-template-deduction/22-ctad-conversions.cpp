#include <utility>

template<typename TA, typename TB>
struct pair {
    TA a;
    TB b;

    pair() {}
    pair(TA a_) : a(std::move(a_)) {}
    pair(TA a_, TB b_) : a(std::move(a_)), b(std::move(b_)) {}
};

int main() {
    struct ConvertibleToPair {
        operator pair<int, double>() { return {10, 20.5}; }
        // operator pair<int, int>() { return {10, 20.5}; }
    } magic;

    // [[maybe_unused]] pair p1 = magic;  // CTAD does not go through conversions, guides are pre-generated
    [[maybe_unused]] pair p2 = magic.operator pair<int, double>();  // CTAD works by seeing `pair<int, double>`
    [[maybe_unused]] pair<int, double> p3 = magic;  // No CTAD
}
