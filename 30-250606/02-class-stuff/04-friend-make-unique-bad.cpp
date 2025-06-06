#include <memory>

// https://abseil.io/tips/134

struct Foo {
    static std::unique_ptr<Foo> make() {
        return std::make_unique<Foo>(10);
    }

private:
    Foo(int) {}

    friend std::unique_ptr<Foo> std::make_unique<Foo>();
};

int main() {
    auto p1 = std::make_unique<Foo>(10);
    auto p2 = Foo::make();
}
