#include <cassert>
#include <iostream>
#include <string>

const int OperationAdd = 1;
const int OperationSub = 2;
const int OperationNeg = 3;

int get_operation(std::string operation) {
    if (operation == "add") {
        return OperationAdd;
    } else if (operation == "sub") {
        return OperationSub;
    } else if (operation == "neg") {
        return OperationNeg;
    } else {
        assert(false);
    }
}

int main() {
    std::string operation_str;  // add/sub/neg
    std::cin >> operation_str;
    int operation_id = get_operation(operation_str);
    if (operation_id == OperationAdd) {
        int a, b;
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    } else if (operation_id == OperationSub) {
        int a, b;
        std::cin >> a >> b;
        std::cout << a - b << "\n";
    } else if (operation_id == OperationNeg) {
        int a;
        std::cin >> a;
        std::cout << -a << "\n";
    }
}
