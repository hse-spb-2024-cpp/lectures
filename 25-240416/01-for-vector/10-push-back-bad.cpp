#include <string>
#include <utility>

template<typename T>
struct stub_vector {
    alignas(alignof(T)) char data[sizeof(T) * 3];
    int size = 0;

    T &operator[](int i) {
        return reinterpret_cast<T&>(data[i * sizeof(T)]);
    }

    void push_back(const T &value) {
        ++size;
        new (&(*this)[size - 1]) T(value);  // If throws: `size` is incorrect.
    }

    ~stub_vector() {
        for (int i = 0; i < size; i++) {
            (*this)[i].~T();
        }
    }
};

int main() {
    stub_vector<std::string> vec;
    std::string foo = "hello";
    vec.push_back(foo);
    vec.push_back(std::string(10'000, 'x'));
}
