#include <cstddef>
#include <iostream>
#include <vector>

// For contests only!
using vi = std::vector<int>;  // C++11

typedef std::vector<std::vector<int>> vvi;

template<typename T>
using vv = std::vector<std::vector<T>>;

int main() {
    vi v1{1, 2, 3};
    std::cout << v1.size() << "\n";  // 3

    vvi v2{{1, 2}, {3}, {4, 5, 6, 7}};
    std::cout << v2.size() << "\n";  // 3

    vv<int> v3{{1}, {2}};
    std::cout << v3.size() << "\n";  // 2
}
