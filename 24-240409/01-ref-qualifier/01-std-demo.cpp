#include <iostream>
#include <memory>
#include <optional>

std::optional<std::unique_ptr<int>> create() {
    return std::make_unique<int>(10);
}

void just_print(const std::unique_ptr<int> &a) {
    if (a) {
        std::cout << "printed " << *a << std::endl;
    } else {
        std::cout << "printed nullptr" << std::endl;
    }
}

void consume_print(std::unique_ptr<int> a) {
    just_print(a);
}

int main() {
     std::optional<std::unique_ptr<int>> a = std::make_unique<int>(20);

     // a.value() is lvalue: method returns reference.
     just_print(a.value());
     // consume_print(a.value());  // CE
     consume_print(std::move(a.value()));

     // <rvalue-optional>.value() is rvalue: https://en.cppreference.com/w/cpp/utility/optional/value
     consume_print(create().value());
     consume_print(create().value());  // Two times to match with future examples
     consume_print(std::move(a).value());
}
