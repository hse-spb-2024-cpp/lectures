#include <vector>

template<typename T>
struct stack {
    std::vector<T> data;

    T pop() noexcept {
        T result = std::move(data.back());
        data.pop_back();
        return result;
    }
};

struct Foo {
    int x;
    Foo(int x) : x(x) {}
};

int main() {
    stack<Foo> s;
    s.data = std::vector<Foo>{1, 2, 3, 4, 5};

    Foo x(123);
    x = s.pop();  // If exception is thrown by `operator=` (C++03), `s` cannot restore stack state.
                  // Looks like strong guarantee violation.
}
