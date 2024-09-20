#include <cassert>
#include <iostream>
#include <string>

enum class Operation {
    Addition,
    Subtraction,
    Negation,
};

Operation get_operation(std::string operation) {
    if (operation == "add") {
        return Addition;
    } else if (operation == "sub") {
        return Subtraction;
    } else if (operation == "neg") {
        return Negation;
    } else {
        assert(false);
    }
}

int main() {
    std::string operation_str;  // add/sub/neg
    std::cin >> operation_str;
    Operation operation_id = get_operation(operation_str);
    if (operation_id == Operation::Addition) {
        int a, b;
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    } else if (operation_id == Operation::Subtraction) {
        int a, b;
        std::cin >> a >> b;
        std::cout << a - b << "\n";
    } else if (operation_id == Operation::Negation) {
        int a;
        std::cin >> a;
        std::cout << -a << "\n";
    }
}
