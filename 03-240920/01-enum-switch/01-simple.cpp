#include <cassert>
#include <iostream>
#include <string>

int main() {
    std::string operation;  // add/sub/neg
    std::cin >> operation;
    if (operation == "add") {
        int a, b;
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    } else if (operation == "sub") {
        int a, b;
        std::cin >> a >> b;
        std::cout << a - b << "\n";
    } else if (operation == "neg") {
        int a;
        std::cin >> a;
        std::cout << -a << "\n";
    }
}
