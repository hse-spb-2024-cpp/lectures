#include <vector>
#include <iostream>

std::vector<int> &some_vector();

std::vector<int> &some_vector() {
    static std::vector<int> vec{1, 2, 3};
    return vec;

    // Better option: never deinitialize
    // https://isocpp.org/wiki/faq/ctors#construct-on-first-use-v2
    // static auto *vec = new std::vector<int>{1, 2, 3};
    // return *vec;
}

struct VeryWeirdObject {
    ~VeryWeirdObject() {
        std::cout << some_vector().size() << "\n";  // May be uninitialized already, e.g. with Microsoft STL (earlier with clang++)
        some_vector().emplace_back(20);
    }
} object;

int main() {
    std::cout << some_vector().size() << "\n";
}
