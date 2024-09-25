#include <vector>

struct MyVector {
    std::vector<int> a();  // compilation error
    std::vector<int> b = std::vector<int>(3);  // ok
    auto c = std::vector<int>(3);  // not ok
};

int main() {
    std::vector<int> a(3);
}
