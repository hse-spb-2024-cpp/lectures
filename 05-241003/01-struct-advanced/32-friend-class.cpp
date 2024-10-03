#include <iostream>

struct Foo {
private:
    int field = 10;

    // All of `FooIncrementer` is now friend of `Foo`.
    // Also possible to make only a single method of `Foo` a friend, but that's more complicated.
    friend struct FooIncrementer;

    // More real-world example: `std::set<int>` and `std::set<int>::iterator`

public:
    int value() const {
        return field;
    }
};

struct FooIncrementer {
    int increment_by;

    void change(Foo &f) const {
        f.field += increment_by;
    }
};

int main() {
    Foo f;
    FooIncrementer inc{100};
    std::cout << f.value() << "\n";
    inc.change(f);
    std::cout << f.value() << "\n";
    inc.change(f);
    std::cout << f.value() << "\n";
}
