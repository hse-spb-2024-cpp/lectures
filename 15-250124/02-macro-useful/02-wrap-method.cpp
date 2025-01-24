#include <iostream>

template<typename F>
void call_twice(F f) {
    f();
    f();
}

struct Foo {
    int x = 10;

    void print_x() {
        std::cout << x << "\n";
    };
};

void print_hello() {
    std::cout << "print_hello\n";
}

int main() {
    Foo f;
    print_hello();
    call_twice(print_hello);

    f.print_x();
    // call_twice(f.print_x);
    // call_twice(&Foo::print_x);
    call_twice([&]() { f.print_x(); });

#define call_twice_m(f) call_twice([&]() { f(); })
    call_twice_m(print_hello);
    call_twice_m(f.print_x);
}
