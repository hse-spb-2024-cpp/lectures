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
        return Operation::Addition;
    } else if (operation == "sub") {
        return Operation::Subtraction;
    } else if (operation == "neg") {
        return Operation::Negation;
    } else {
        assert(false);
    }
}

int main() {
    std::string operation_str;  // add/sub/neg
    std::cin >> operation_str;
    Operation operation_id = get_operation(operation_str);
    switch (operation_id) {
        case Operation::Addition: {
            int a, b;
            std::cin >> a >> b;
            std::cout << a + b << "\n";
        } break;
        default: {
            std::cout << "Unknown command\n";
        } break;
    }
}
