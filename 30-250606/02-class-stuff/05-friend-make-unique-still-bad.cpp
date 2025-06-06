#include <memory>

// https://abseil.io/tips/134

struct Foo {
    static std::unique_ptr<Foo> make() {
        return std::make_unique<Foo>(10);
    }

private:
    Foo(int) {}

    friend std::unique_ptr<Foo> std::make_unique<Foo>(int&&);
    // (1) No guarantee that `make_unique` calls `Foo()` itself :(
};

int main() {
    auto p1 = std::make_unique<Foo>(10);  // (2) Can call arbitrary `make_unique` :(
    auto p2 = Foo::make();
}
