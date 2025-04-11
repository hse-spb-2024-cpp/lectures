#include <string>
#include <utility>

template<typename T>
struct not_optional {
    alignas(alignof(T)) unsigned char data[sizeof(T)];

    void insert(const T &value) {
        new (&data) T(value);
    }

    void insert(T &&value) {
        new (&data) T(std::move(value));
    }

    template<typename Arg1, typename Arg2>
    void emplace(Arg1 arg1, Arg2 arg2) {
        // FIXME: use perfect forwarding + variadic templates (later)
        new (&data) T(arg1, arg2);
    }

    void reset() {
        reinterpret_cast<T&>(data).~T();
    }
};

int main() {
    not_optional<std::string> v;
    std::string foo = "hello";

    v.insert(foo);  // 1 copy ctor (best!)
    v.reset();

    v.emplace(10'000, 'x');  // 1 ctor (best!)
    v.reset();
}
