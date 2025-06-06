#include <memory>

// https://abseil.io/tips/134

struct Foo {
    static std::unique_ptr<Foo> make() {
        return std::make_unique<Foo>(secret_tag{}, 10);
    }

private:
    struct secret_tag {};

public:
    Foo(secret_tag, int) {}
};

struct any_creator {
    template<typename T>
    operator T() { return T{}; }
};

int main() {
    // auto p1 = std::make_unique<Foo>(Foo::secret_tag{});
    auto p2 = Foo::make();  // this is good
    auto p3 = std::make_unique<Foo>(any_creator{}, 10);
}
