#include <memory>

// https://abseil.io/tips/134

struct Foo {
    static std::unique_ptr<Foo> make() {
        return std::make_unique<Foo>();
    }

private:
    Foo() {}

    friend std::unique_ptr<Foo> std::make_unique<Foo>();
};

int main() {
    auto p1 = std::make_unique<Foo>();
    auto p2 = Foo::make();
}
