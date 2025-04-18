#include <cassert>
#include <string>
#include <utility>

template<typename T>
struct stub_vector {
    T *buffer = nullptr;
    int size = 0;
    int capacity = 0;

    stub_vector() {}
    stub_vector(const stub_vector &) { /* FIXME */ }
    ~stub_vector() { /* FIXME */ }
    void push_back(const T &) { /* FIXME */ }

    stub_vector &operator=(stub_vector other) {  // strong exception safety, no trouble with aliasing
        std::swap(buffer, other.buffer);
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
        return *this;
    }
};

int main() {
    stub_vector<std::string> vec1, vec2;
    vec1.push_back(std::string(100, 'a'));
    vec1.push_back(std::string(100, 'b'));
    vec2.push_back(std::string(100, 'x'));
    vec2.push_back(std::string(100, 'y'));

    vec1 = vec2;  // Ideally, no reallocation. But not now :(
}
