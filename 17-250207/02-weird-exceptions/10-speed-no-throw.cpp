#include <chrono>
#include <iostream>

// -fno-exceptions did not make a difference for me as well.

// TODO: disable some optimizations?

bool foobar(int a, int b, [[maybe_unused]] bool please_throw) noexcept {
    if (please_throw) {
        if (a % b) {
//            throw 0;
        }
        return true;
    }
    return a % b == 0;
}

const int STEPS = 100'000'000;

int main() {
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < STEPS; i++) {
//        try {
          foobar(10, 3, false);
//        } catch (...) {
//        }
    }

    auto duration = std::chrono::steady_clock::now() - start;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms\n";
}
