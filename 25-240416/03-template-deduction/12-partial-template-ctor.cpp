#include <iostream>

template<typename T, int Value>
struct Foo {
    Foo() {}

    Foo(const Foo<T, Value> &) {
        std::cout << "copy constructor" << std::endl;
    }

    template<int Value2>
    Foo(const Foo<T, Value2> &) {  // `<T, Value2 + 0>` already breaks
        std::cout << Value2 << " --> " << Value << std::endl;
    }
};

int main() {
    [[maybe_unused]] Foo<int, 10> x;
    [[maybe_unused]] Foo<int, 11> y;
    [[maybe_unused]] Foo<char, 11> z;

    // Cannot specify explicit template arguments for constructors.
    [[maybe_unused]] Foo<int, 10> x1 = x;
    [[maybe_unused]] Foo<int, 10> x1b(x);
    [[maybe_unused]] Foo<int, 10> x2 = y;
    [[maybe_unused]] Foo<int, 10> x2b(y);
    // [[maybe_unused]] Foo<int, 10> x3 = z;
}
