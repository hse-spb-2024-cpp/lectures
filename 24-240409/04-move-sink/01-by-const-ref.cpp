#include <string>
#include <utility>

template<typename T>
struct not_optional {
    alignas(alignof(T)) unsigned char data[sizeof(T)];

    void insert(const T &value) {
        new (&data) T(value);
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

    v.insert(std::string(10'000, 'x'));  // 1 ctor, 1 copy, 1 dtor
    v.reset();
}
