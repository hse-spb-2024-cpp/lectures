#include <iostream>

template<typename T, int Value>
struct Foo {
    template<typename W>
    void foo(const W &) {
    }

    template<typename U, typename W>
    void bar(const W &) {
    }

    template<typename T2, int Value2>
    bool operator==(const Foo<T2, Value2> &) {
        return true;
    }
};

int main() {
    [[maybe_unused]] Foo<int, 10> x;
    [[maybe_unused]] Foo<int, 11> y;
    [[maybe_unused]] Foo<char, 11> z;

    x.foo(z);  // argument deduction works
    x.foo<>(z);  // argument deduction works
    x.bar<int>(z);  // partial argument deduction works

    x == y;  // Oops: Foo<int, 10> == Foo<int, 11>
    x == z;  // Oops: Foo<int, 10> == Foo<char, 11>
}
