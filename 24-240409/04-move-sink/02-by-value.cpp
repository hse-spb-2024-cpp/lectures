#include <string>
#include <utility>

template<typename T>
struct not_optional {
    alignas(alignof(T)) unsigned char data[sizeof(T)];

    void insert(T value) {
        new (&data) T(std::move(value));
    }

    void reset() {
        reinterpret_cast<T&>(data).~T();
    }
};

int main() {
    not_optional<std::string> v;
    std::string foo = "hello";

    v.insert(foo);  // 1 copy ctor, 1 move ctor, 1 dtor
    v.reset();

    v.insert(std::string(10'000, 'x'));  // 1 ctor, 1-2 move ctor, 1-2 dtor
    v.reset();
}
