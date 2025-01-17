#include <functional>
#include <iostream>
#include <vector>

struct Base {
    int x = 10;

    // https://cdecl.org
    using print_impl_ptr = void (*)(Base *);  // std::function<void(Base*)>, no captures
    static void print_impl(Base *self) {  // self ~ this
        std::cout << "x = " << self->x << "\n";
    }

    print_impl_ptr print_ptr = print_impl;
    // pretty_print_impl_ptr pretty_print_ptr;
    // read_impl_ptr read_ptr;

    void print() {
        print_ptr(this);
    }
};

struct Derived : Base {
    int y = 20;

    static void print_impl(Base *self_b) {
        Derived *self = static_cast<Derived *>(self_b);
        std::cout << "x = " << self->x << ", y = " << self->y << "\n";
    }

    Derived() {
        print_ptr = print_impl;
    }
};

int main() {
    Base b;
    Derived d;
    b.print();
    d.print();

    Base &db = d;
    db.print();

    std::cout << sizeof(Base) << ", " << sizeof(Derived) << "\n";

    [[maybe_unused]] std::vector<Derived> vec(1'000'000);
}
