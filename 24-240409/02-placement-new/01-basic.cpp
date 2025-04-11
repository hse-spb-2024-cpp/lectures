#include <iostream>
#include <memory>
#include <vector>

struct Foo {
    std::vector<int> v = std::vector{1, 2, 3};

    Foo() {
        std::cout << "Constructed at " << this << std::endl;
    }

    ~Foo() {
        std::cout << "Destructed at " << this << std::endl;
    }
};

int main() {
    alignas(alignof(Foo)) unsigned char data[sizeof(Foo)];
    std::cout << "Got memory, size=" << sizeof(data) << ", location=" << &data
              << std::endl;

    // We separate "memory allocation" from "object creation".
    // Previously `new T` did both. Now we only need it to call constructor.

    // #include <memory> for "placement new":
    Foo *f = new (data) Foo();  // Best practice.

    std::cout << f->v.size() << std::endl;
    std::cout << "bytes:";
    for (unsigned char c : data) {
        std::cout << ' ' << static_cast<int>(c);
    }
    std::cout << std::endl;

    f->~Foo();  // Explicit destructor call/pseudodestructor. No memory
                // deallocation, so it can be any memory.
    // delete f;  // Destructor + memory deallocation.

    // f->v;  // UB
    (void)data[123];  // OK
    data[123] = 50;  // OK
}
