#include <memory>

// https://abseil.io/tips/134

struct Foo {
    static std::unique_ptr<Foo> make() {
        return std::unique_ptr<Foo>(new Foo());  // good
    }

private:
    Foo() {}
};

int main() {
    // auto p1 = std::make_unique<Foo>();  // hence, this is bad
    auto p2 = Foo::make();  // this is good
}
