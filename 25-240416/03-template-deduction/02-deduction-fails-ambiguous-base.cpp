#include <vector>

template<typename T>
struct Base {
    Base() {}
};

struct Derived1 : Base<int> {};
struct Derived2 : Base<double> {};
struct Derived3 : Base<int>, private Base<double> {
};

template<typename T>
void foo(const Base<T> &) {
}

int main() {
    foo(Base<int>());
    foo(Derived1());
    foo(Derived2());
    foo<int>(Derived3());
    // foo(Derived3());  // compilation error: ambiguous base, even though Base<double> is private

    // Order:
    // 1. Deduce template arguments.
    // 2. Try to call: check permissions, conversions, etc.
}
