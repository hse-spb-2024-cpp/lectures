#include <utility>

template<typename TA, typename TB>
struct pair {
    TA a;
    TB b;

    pair() {}
    pair(TA a_) : a(std::move(a_)) {}
    pair(TA a_, TB b_) : a(std::move(a_)), b(std::move(b_)) {}
};

template<typename TA, typename TB>
pair<TA, TB> make_pair(TA a_, TB b_) {
    return {std::move(a_), std::move(b_)};
}

int main() {
    // Work around + life before C++17: using argument deduction for functions.
    [[maybe_unused]] auto p1 = make_pair(10, 20);
    [[maybe_unused]] auto p2 = make_pair<double>(10, 20);
}
