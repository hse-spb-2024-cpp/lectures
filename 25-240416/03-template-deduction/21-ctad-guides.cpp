#include <utility>

template<typename TA, typename TB>
struct pair {
    TA a;
    TB b;

    pair() {}
    pair(TA a_) : a(std::move(a_)) {}
    pair(TA a_, TB b_) : a(std::move(a_)), b(std::move(b_)) {}
};
// "Deduction guides" for (1) are generated from constructors by default:
// https://en.cppreference.com/w/cpp/language/class_template_argument_deduction

// template<typename TA, typename TB> pair(TA, TB) -> pair<TA, TB>;  // implicitly generated
template<typename TA> pair(TA) -> pair<TA, int>;  // (XXX) explicit deduction guide

int main() {
    [[maybe_unused]] pair<double, int> p4 = pair(50.0);  // Works only if there is deduction guide (XXX).
}
