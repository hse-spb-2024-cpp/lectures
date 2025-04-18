#include <cassert>
#include <string>
#include <utility>

template<typename T>
struct stub_vector {
    T *buffer = nullptr;
    int size = 0;
    int capacity = 0;

    stub_vector() {}
    stub_vector(const stub_vector &) { /* TODO */ }
    ~stub_vector() { /* TODO */ }
    void push_back(const T &) { /* TODO */ }

    stub_vector &operator=(const stub_vector &other) {
        if (this == &other) {
            return *this;
        }
        if (capacity >= other.size) {
            assert(size == other.size);  // FIXME: create/destroy elements
            for (int i = 0; i < other.size; ++i) {
                buffer[i] = other.buffer[i];
            }
        } else {
            // FIXME: allocate buffer, etc
        }
        return *this;
    }
    // FIXME: move constructor, move assignment
};

int main() {
    stub_vector<std::string> vec1, vec2;
    vec1.push_back(std::string(100, 'a'));
    vec1.push_back(std::string(100, 'b'));
    vec2.push_back(std::string(100, 'x'));
    vec2.push_back(std::string(100, 'y'));

    vec1 = vec2;  // No reallocation!
}
