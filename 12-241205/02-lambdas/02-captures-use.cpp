#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
    {
        // 1
        std::vector<int> v{1, 2, 3, 4, 5};
        std::sort(v.begin(), v.end(), [&](int a, int b) {
            return a > b;
        });
    }
    {
        // 2
        std::vector<std::function<void()>> funcs;
        for (int i = 0; i < 10; i++) {
            funcs.push_back([=]() {
                std::cout << i << "\n";
            });
        }
        funcs[3]();
    }
}
