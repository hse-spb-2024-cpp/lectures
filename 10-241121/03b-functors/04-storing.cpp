#include <iostream>

template<typename F>
struct Caller {
    F operation;

    void operator()() {
        operation(10);
    }
};

struct Printer {
    void operator()(int a) const {
        std::cout << a << "\n";
    }
};

int main() {
    Caller<Printer> c{Printer{}};
    c();
    c();
}
