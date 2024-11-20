#include <functional>
#include <iostream>

void apply(std::function<void(int)> operation) {
    std::cout << "Calling with 10\n";
    operation(10);
}

struct Print {
    void operator()(int x) const {
        std::cout << x << "\n";
    }
};

struct PrintTwice {
    void operator()(int x) const {
        std::cout << x << ", " << x << "\n";
    }
};

void no_op(int) {}

int main() {
    Print p;
    p(523);

    apply(no_op);
    apply(Print{});
    apply(Print{});
    apply(PrintTwice{});
    apply([](int x) { std::cout << "lambda: " << x << "\n"; });
    // apply(12);
}
