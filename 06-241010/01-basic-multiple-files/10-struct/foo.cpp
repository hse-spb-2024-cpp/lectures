#include <vector>
#include <iostream>



struct Foo {
    int a = 10;
    std::vector<int> v;

    void method1();

    void method2() {
        std::cout << "method_unused() called " << a << "\n";
    }
};

Foo get_foo() {
    return Foo{};
}

void Foo::method1() {
    std::cout << "method2() called " << a << "\n";
}
