#include <iostream>
#include <type_traits>

// https://people.eecs.berkeley.edu/~brock/blog/detection_idiom.php

struct Foo {
    void foo() {}
};

struct Bar {
};

namespace detect_foo {
// What if 'const T &'?
template<typename T>
auto impl(T &x) -> decltype(x.foo(), std::true_type{});
std::false_type impl(...);  // C-style variadic argument (ellipsis) has the lowest priority in overload resolution

template<typename T>
constexpr bool has_foo = decltype(impl(std::declval<T&>()))::value;

// In C++03:
struct yes { char x[2]; };
struct no { char x[1]; };
// decltype() --> sizeof(impl(......)) == sizeof(yes)
// declval() --> manual, no implementation
};

int main() {
    std::cout << detect_foo::has_foo<Foo> << "\n";
    std::cout << detect_foo::has_foo<Bar> << "\n";
}
