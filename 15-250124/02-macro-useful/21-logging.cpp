#include <iostream>

int foo() {
    std::cout << "Works a lot!\n";
    return 10;
}

bool logging_enabled = true;

#define log(x) if (logging_enabled) { std::cout << x << "\n"; }
// LOTS OF TROUBLES DO NOT USE

int main(int argc, char*[]) {
    if (argc > 1) {
        logging_enabled = false;
    }

    if (logging_enabled) {
        std::cout << foo() << "\n";
    }
    log(foo());
}
