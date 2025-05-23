#include <cassert>
#include <iostream>
#include <string>
#include <vector>

struct A { int val = 0; };
struct B { int val = 0; };
struct C { int val = 0; };
struct D { int val = 0; };

template<typename T>
void println(const T &v) requires requires { std::cout << v.val; } {
    std::cout << v.val << "\n";
}

struct E { int val2 = 0; };
struct F { int val2 = 0; };

#if 1
template<typename T>
void println(const T &v) requires requires { std::cout << v.val2; } {
    std::cout << v.val2 << "\n";
}
#endif

int main() {
    A a{10};
    println(a);  // 10

    std::string s = "hello";
    // println(s);

    [[maybe_unused]] E e{40};
    println(e);
}
