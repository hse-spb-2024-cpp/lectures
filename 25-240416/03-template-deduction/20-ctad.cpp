#include <utility>
#include <vector>

// C++17: class template argument deduction (CTAD)
template<typename TA, typename TB>
struct pair {
    TA a;
    TB b;

    pair() {}
    pair(TA a_) : a(std::move(a_)) {}  // Will not be used by CTAD by default: unable to deduce TB.
    pair(TA a_, TB b_) : a(std::move(a_)), b(std::move(b_)) {}
};
// CTAD needs two things:
// 1. Deduce class(!) template arguments from constructor arguments.
// 2. Choose appropriate constructor. Note that constructors may be templated themselves.

int main() {
    [[maybe_unused]] auto p1 = pair(10, 20);
    [[maybe_unused]] pair p2(10, 20);
    [[maybe_unused]] pair<double, int> p3(10, 20);
    // [[maybe_unused]] pair<double> p4(10, 20);  // Either all arguments are specified, or use full CTAD only. No partial.

    std::vector v{1, 2, 3};  // CTAD
}
