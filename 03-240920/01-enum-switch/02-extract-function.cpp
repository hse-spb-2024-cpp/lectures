#include <cassert>
#include <iostream>
#include <string>

int get_operation(std::string operation) {
    if (operation == "add") {
        return 1;
    } else if (operation == "sub") {
        return 2;
    } else if (operation == "neg") {
        return 3;
    } else {
        assert(false);
    }
}

int main() {
    std::string operation_str;  // add/sub/neg
    std::cin >> operation_str;
    int operation_id = get_operation(operation_str);
    if (operation_id == 1) {
        int a, b;
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    } else if (operation_id == 2) {
        int a, b;
        std::cin >> a >> b;
        std::cout << a - b << "\n";
    } else if (operation_id == 3) {
        int a;
        std::cin >> a;
        std::cout << -a << "\n";
    }
}
