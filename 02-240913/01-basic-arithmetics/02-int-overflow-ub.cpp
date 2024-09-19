#include <iostream>

int main() {
    int i = 1;
    while (true) {
        i = i * 3;  // UB is typically caught by -fsanitize=undefined, execution
                    // continues
        std::cout << i << "\n";
        if (i < 0) {  // Typically optimized out by the compiler. See https://godbolt.org/z/TrxjWa1Wh
            // How to detect postfactum? No way. See https://thephd.dev/c-undefined-behavior-and-the-sledgehammer-guideline
            std::cout << "Overflow detected\n";
            return 0;
        }
    }
}
