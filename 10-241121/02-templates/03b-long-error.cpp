#include <memory>
#include <vector>

int main() {
    std::vector<std::unique_ptr<int>> v1;
    std::vector<std::unique_ptr<int>> v2 = v1;
}
